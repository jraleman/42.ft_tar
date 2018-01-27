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

/*
** Modifies data to conform with the input requirements of another function.
*/

static int	header_preprocessor(int count, char const *names[])
{
	int		i;

	i = 0;
	while (i < (count - 1))
	{
		// add metadata block
		i += 1;
	}
	return (0);
}

/*
** Compress multiple files to a single archive.
** Need to add metadata about the info of the files to the archive.
*/

int		ft_archive(int count, char const *names[])
{
	// Create Header
	printf("Pre-processing files: %s\n", "--list of files--");
	printf("Collecting metadata...\n");
	header_preprocessor(count, names);
	printf("Compiling header information...\n");
	// header_compile();
	printf("Creating and writting header to archive...\n");
	// header_write();

	// read_block()

	// body_writer()

	// print_stats()
	return (0);
}
