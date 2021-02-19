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

// Returns an array of flags
char	**get_flags(char *arg)
{
	char	**parse = NULL;
	(void)arg; // <- ignore this, just here to compile

	// flags to include
		// VRB_FLG	"-v"
		// EXT_FLG	"-x"
		// CRT_FLG	"-c"
	return parse;
}

// Handle flags taken from an argument
static int		handle_flag(t_tar *tar, char *arg)
{
	char		*flag;
	char		**flags = get_flags(arg);
	int			valid = is_flag(arg);

	if (valid == OK_CODE)
	{
		for (int i = 0; i < FLG_NUM; i += 1) 
		{
			// Refactor this into a function, like 
			// Check this out: https://stackoverflow.com/a/47396854 
			flag = flags[i];
			if (!tar->flag.c && !strncmp(flag, CRT_FLG, 2))
				tar->flag.c = TRUE;
			if (!tar->flag.v && !strncmp(flag, VRB_FLG, 2))
				tar->flag.v = TRUE; 
			if (!tar->flag.x && !strncmp(flag, EXT_FLG, 2))
				tar->flag.x = TRUE; 
		}
	}
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
		// do file stuff...
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
	
	return is_extract(tar) ? unarchive(tar, argc, argv) : archive(tar, argc, argv);
	// refactor -> return is_extract(tar) ? unarchive(tar) : archive(tar);
}
