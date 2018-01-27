/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 04:01:52 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/27 04:01:54 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_archive.h"

/*
** Print ft_archive basic usage message.
*/

static void	print_usage(char const *progname)
{
	printf("%s file_archive [file1 ... fileN]\n", progname);
	return ;
}


/*
** Main function:
**
** argv[0] -----> program name
** argv[1] -----> archive
** argv[2...N] -> files
*/

int			main(int argc, char const *argv[])
{
	int		*fds;

	if (argc > 2)
	{
		if (!(fds = (int *)malloc(sizeof(int) * (argc - 2))))
		{
			printf("%s\n", "Malloc failed!");
			return (-1);
		}
		// open files to file descriptor
		if (ft_archive(fds, argv) != 0)
		{
			printf("%s\n", "Failed to create archive!");
			return (-2);
		}
	}
	else
	{
		print_usage(argv[0]);
	}
	return (0);
}
