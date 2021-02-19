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

#include "header.h"

// Add files to archive
static int	add_file(FILE *tar, char *name)
{
	int		ret = OK_CODE;
	FILE	*input = NULL;
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
int			ft_archive(char *names[], int count)
{
	int		arg_index = 1;
	FILE	*tar = fopen(names[1], "wb");
	// t_mdata	*ptr = NULL;

	if (tar) 
	{
		while (++arg_index < count)
			if (add_file(tar, names[arg_index]) != OK_CODE)
				break ;
		expand_file(tar, BLOCK_SIZE * 2);
		fclose(tar);
	}
	return arg_index == count ? OK_CODE : archive_error();
}
