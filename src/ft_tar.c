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

static int		save_option(int *opt, char *flag)
{
	char		*valid_flags[FLG_NUM] = 
	{
		VRB_FLG,
		EXT_FLG,
		CRT_FLG,
	};

	for (int i = 0; i < FLG_NUM; i += 1) 
		if (!*opt && !strncmp(flag, valid_flags[i], 2))
			*opt = TRUE;
	return *opt;
}

// Returns TRUE if a flag is set, FALSE otherwise
static int		set_flags(t_tar *tar, char **flags)
{
	for (int i = 0; i < FLG_NUM; i += 1) 
	{
		save_option(&tar->flag.c, flags[i]);
		save_option(&tar->flag.v, flags[i]);
		save_option(&tar->flag.x, flags[i]);
	}
	return tar->flag.c || tar->flag.x || tar->flag.v;
}

// Returns an array of flags
static char		**get_flags(char *arg)
{
	char	**parse = NULL;
	(void)arg; // <- ignore this, just here to compile

	return parse;
}

// Handle flags taken from an argument
static int		handle_flag(t_tar *tar, char *arg)
{
	char		**flags = get_flags(arg);
	int			valid = is_flag(arg);

	if (valid == OK_CODE)
		set_flags(tar, flags);
	return valid;
}

// Handle a file taken from an argument
static int		handle_file(t_tar *tar, char *arg)
{
	int valid = is_flag(arg) && is_file(arg);
	if (valid == OK_CODE)
	{
		(void)tar; // <- ignore this, just here to compile
		(void)arg; // <- ignore this, just here to compile
	}
	return valid;
}

// Parses the argument, handling either flag or file
static int		parse_arg(t_tar *tar, char *arg)
{
	return handle_flag(tar, arg) || handle_file(tar, arg);
}

// Initialize t_tar structure
static t_tar	*init_tar(int argc, char *argv[])
{
	t_tar		*tar = malloc(sizeof(t_tar));

	for (int i = 0; tar && i < argc; i += 1) 
		if (!parse_arg(tar, argv[i]))
			tar = NULL;
	return tar;
}

// Process and returns status of archive creation/extraction
int				ft_tar(int argc, char *argv[])
{
	t_tar		*tar = init_tar(argc, argv);
	
	return is_extract(tar) ? unarchive(tar) : archive(tar, argc, argv);
}
