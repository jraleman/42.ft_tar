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

// Checks if an argument is a file
// TODO: implement function
int		is_file(char *arg)
{
	return arg ? TRUE : FALSE;
}

// Prints verbose output, returns number of bytes
int		print_verbose(t_tar *tar, char *msg)
{
	return tar && tar->flag.v == TRUE ? printf(">> %s\n", msg) : 0;
}

// Checks if there is a conflict between flags
int		is_conflict(t_tar *tar)
{
	return tar && tar->flag.x && tar->flag.c;
}

// Returns an array of flags
char	**get_flags(char *flag)
{
	char	**parse = NULL;
	(void)flag; // <- ignore this, just here to compile

	// flags to include
	// ...
	return parse;
}

// Checks if an argument is a flag
// TODO: implement function
int		is_flag(char *arg)
{
	return arg ? TRUE : FALSE;
}

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
size_t	get_filesize(char *filename)
{
	struct stat	st;
	stat(filename, &st);
	return st.st_size;
}
