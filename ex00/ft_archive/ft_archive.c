/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_archive.h"

// Prints usage message, returns error code
static int	usage_error(char *name)
{
	printf("%s archive_name [file_1 ... file_N]\n", name);
	return ERR_USAGE;
}

// Prints archive creation error, returns code
static int	archive_error(void) 
{
	printf("Failed to create archive!\n");
	return ERR_CREATE;
}

// Expands a file
static void	expand_file(FILE *fp, size_t amount)
{
	while (--amount)
		fputc(0, fp);
}

// Add files to archive
static int	add_file(FILE *tar, char *name)
{
	int		ret = OK_CODE;
	FILE	*input;
	size_t	index = ftell(tar);
	size_t	offset = index % BLOCK_SIZE;

	if (offset != 0)
		expand_file(tar, BLOCK_SIZE - offset);
	index = ftell(tar);
	expand_file(tar, sizeof(t_mdata));
	if (!(input = fopen(name, "rb")))
		ret = ERR_OPEN;
	fclose(input);
	return ret;
}

// Add multiple files to a single archive
static int	ft_archive(char *names[], int count)
{
	int		ret = OK_CODE;
	int		arg_index = 1;
	FILE	*tar = fopen(names[1], "wb");

	if (tar) 
	{
		while (++arg_index < count)
			if (add_file(tar, names[arg_index]) != OK_CODE)
				break ;
		expand_file(tar, BLOCK_SIZE * 2);
		fclose(tar);
		ret = arg_index == count;
	}
	else 
		ret = ERR_CREATE;
	return ret;
}

// Main function
int			main(int argc, char *argv[])
{
	int		ret = OK_CODE;

	if (argc > 3 && ft_archive(argv, argc) != OK_CODE)
		ret = archive_error();
	else if (argc < 3)
		ret = usage_error(argv[0]);
	return ret;
}
