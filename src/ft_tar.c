/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tar.h"

// See if we should create or extract an archive
static int		should_extract(t_tar *tar)
{
	return tar && tar->flag.x ? TRUE : FALSE;
}

// Initialize t_tar structure
static t_tar	*init_tar(int argc, char *argv[])
{
	t_tar		*tar = malloc(sizeof(t_tar));

	// save argc and argv into memory? just save what i need...
	// handle flags here, maybe create flag.c
	// if -x flag is here, set to = FALSE;
	(void)argc;  // <- ignore this, just here to compile
    (void)argv;  // <- ignore this, just here to compile
	return tar;
}

// Process and returns status of archive creation/extraction
int				ft_tar(int argc, char *argv[])
{
	t_tar		*tar = init_tar(argc, argv);
	
	return should_extract(tar) ? unarchive(argc, argv) : archive(argc, argv);
	// return should_extract(tar) ? unarchive(tar) : archive(tar);
}
