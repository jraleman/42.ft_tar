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

#include "header.h"

// Prints usage message, returns error code
int		usage_error(char *name)
{
	printf("%s archive_name [file_1 ... file_N]\n", name);
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