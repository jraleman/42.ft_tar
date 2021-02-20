/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

// Sets tar archive header
static void	set_header(t_tar *tar, FILE *archive)
{
	(void)tar;
	(void)archive;
}

// Sets tar archive body
static void	set_body(t_tar *tar, FILE *archive)
{
	(void)tar;
	(void)archive;
}

// Renames archive file to make backup
static void	make_backup(char *name)
{
	// Rename to `${archive.backup_{NUM}.tar}`
	(void)name;
}

// Create an archive file
static FILE	*create_archive(char *name)
{
	if (is_file(name))
		make_backup(name);
	return fopen(name, "wb");
}

// Add files to archive
static int	add_file(FILE *archive, char *filename)
{
	FILE	*input = NULL;
	int		size = get_filesize(filename);

	(void)archive;  // <- ignore this, just here to compile
	(void)size; // <- ignore this, just here to compile
	// Open-and-close function
	// copy_content(char *filename)???
	if (!(input = fopen(filename, "rb")))
		return ERR_OPEN;
	fclose(input);
	return OK_CODE;
}

// Add multiple files to a single archive
// maybe rename to create.c
int			archive(t_tar *tar, int total, char *files[])
{
	int		arg_index = 1;
	FILE	*archive = create_archive(files[1]);

    print_verbose(tar, ">> running: archive()");
	if (archive && !is_conflict(tar))
	{
		while (++arg_index < total)
			if (add_file(archive, files[arg_index]) != OK_CODE)
				break ;
		set_header(tar, archive);
		set_body(tar, archive);
		// expand_file(archive, BLOCK_SIZE * 2);
		fclose(archive);
	}
	return arg_index == total ? OK_CODE : archive_error();
}
