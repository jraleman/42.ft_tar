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

#include <stdio.h>

/*
** Compress multiple files to a single archive.
** Need to add metadata about the info of the files to the archive.
*/

int		ft_archive()
{
	return (0);
}

/*
** Print ft_archive basic usage message.
*/

void	print_usage(char *progname)
{
	printf("%s file_archive file1 [file2 ... fileN]\n", progname);
	return ;
}

/*
** Main function:
**
** argv[0] -----> program name
** argv[1] -----> archive
** argv[2...N] -> files
*/

int		main(int argc, char const *argv[])
{
	// int *fds;

	// if (!(fds = (int *)malloc(sizeof(int) * (argc - 2)))
	// {
			// printf("%s\n", "Malloc failed!");
			// return (-1);
	// }
	if (argc > 2)
	{
		// open files to file descriptor?
		// ft_archive(int *fds, char **argv);
	}
	else
	{
		print_usage(argv[0]);
	}
	return (0);
}
