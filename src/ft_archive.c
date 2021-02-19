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

#include "ft_tar.h"

// Add files to archive
static int	add_file(FILE *archive, char *filename)
{
	FILE	*input = NULL;
	int		size = get_filesize(filename);

	(void)archive;  // <- ignore this, just here to compile
	// Open and close ()
	if (!(input = fopen(filename, "rb")))
		return ERR_OPEN;
	fclose(input);
	return OK_CODE;
}

// Add multiple files to a single archive
int			ft_archive(int total, char *files[])
{
	int		arg_index = 1;
	FILE	*archive = fopen(files[1], "wb");
	// t_mdata	*ptr = NULL;

	if (archive) 
	{
		while (++arg_index < total)
			if (add_file(archive, files[arg_index]) != OK_CODE)
				break ;
		// create_header();
		// create_body();
		expand_file(archive, BLOCK_SIZE * 2);
		fclose(archive);
	}
	return arg_index == total ? OK_CODE : archive_error();
}
