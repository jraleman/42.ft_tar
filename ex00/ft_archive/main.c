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

static void	print_usage(char *progname)
{
	printf("%s file_archive [file1 ... fileN]\n", progname);
	return ;
}

/*
** Main function:
**
** argv[0] -----> program name
** argv[1] -----> archive

	argv[1] == "directory/HELLO.txt"

	directory/HELLO.txt

** argv[2...N] -> files
*/

int			main(int argc, char *argv[])
{
	FILE	*tar;

	if (argc > 2)
	{
		tar = fopen(argv[1], "wb");
		if (ft_archive(tar, argv, argc) != 0)
		{
			printf("%s\n", "Failed to create archive!");
			return (-1);
		}
	}
	else
	{
		print_usage(argv[0]);
	}
	return (0);
}
