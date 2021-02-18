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
** Prints ft_archive basic usage message.
*/

static int	output_usage(char *name)
{
	printf("%s archive_name [file_1 ... file_N]\n", name);
	return (1);
}

/*
** Prints ft_archive basic usage message.
*/

static int output_create_error(void) 
{
	printf("Failed to create archive!\n");
	return (2);
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
	int		ret;

	ret = 0;
	if (argc > 2 && !ft_archive(argv[0], argv, argc))
		ret = output_create_error();
	else
		ret = output_usage(argv[0]);
	return ret;
}
