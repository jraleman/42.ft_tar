/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unarchive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

// Extract multiple files from a single archive
// maybe rename to extract.c
int			unarchive(t_tar *tar, int total, char *files[])
{
    print_verbose(tar, ">> running: unarchive()");
    (void)total;  // <- ignore this, just here to compile
    (void)files;  // <- ignore this, just here to compile
    (void)tar;  // <- ignore this, just here to compile
	return OK_CODE;
}
