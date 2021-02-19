/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

// Prints usage message, returns error code
int		usage_error(char *name)
{
	printf("%s archive.tar [flags] [file_1 ... file_N]\n", name);
	return ERR_USAGE;
}

// Prints archive creation error, returns code
int		archive_error(void) 
{
	printf("Failed to create archive!\n");
	return ERR_CREATE;
}

// Expands a file
void	expand_file(FILE *fp, size_t amount)
{
	while (--amount)
		fputc(0, fp);
}

// Gets the memory size of a file
// size_t		get_filesize(FILE *fp)
// {
// 	size_t	index = ftell(fp);
// 	size_t	offset = index % BLOCK_SIZE;
// 	if (offset != 0)
// 		expand_file(fp, BLOCK_SIZE - offset);
// 	index = ftell(fp);
// 	expand_file(fp, sizeof(t_mdata));
// 	return index;
// }

// Gets the memory size of a file
// size_t	get_filesize(FILE *fp)
// {
//     size_t size = 0;
//     fseek(fp, 0L, SEEK_END);
//     size = ftell(fp);
//     fseek(fp, 0L, SEEK_SET);
//     return size;
// }

// Gets the memory size of a file
size_t	get_filesize(char *filename)
{
	struct stat	st;
	stat(filename, &st);
	return st.st_size;
}
