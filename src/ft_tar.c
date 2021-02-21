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

// Save flag option
static void		save_option(int *opt, char *flag)
{
	char		*valid_flags[FLAGS_NUM] = {FLAGS};

	for (int i = 0; i < FLAGS_NUM; i += 1) 
		if (!*opt && !strncmp(flag, valid_flags[i], 2))
			*opt = TRUE;
}

// Returns TRUE if a flag is set, FALSE otherwise
static void		set_flags(t_tar *tar, char *arg)
{
	save_option(&tar->flag.c, arg);
	save_option(&tar->flag.v, arg);
	save_option(&tar->flag.x, arg);
}

// Handle flags taken from an argument
static int		handle_flag(t_tar *tar, char *arg)
{
	int			valid = is_flag(arg);

	if (valid == OK_CODE)
		set_flags(tar, arg);
	return valid;
}

// Copy filename to tar structure
static void		copy_filename(t_tar *tar, char *name, int count)
{
	for (int i = 0; i < count; i += 1)
	{
		if (!tar->files[i])
		{
			tar->files[i] = strdup(name);
			printf(">><<, %s\n", name);
			break;
		}
	}
}

// Handle a file taken from an argument
static int		handle_file(t_tar *tar, char *arg, int count)
{
	int valid = is_file(arg);

	if (valid == OK_CODE)
		copy_filename(tar, arg, count);
	return valid;
}

// Parses the argument, handling either flag or file
static int		parse_arg(t_tar *tar, char *arg, int count)
{
	return handle_flag(tar, arg) || handle_file(tar, arg, count);
}

// Initialize t_tar structure
static t_tar	*init_tar(int argc, char *argv[])
{
	t_tar		*tar = malloc(sizeof(t_tar));

	tar->files = (char **)calloc(argc, sizeof(char *));
	for (int i = 1; tar && i < argc; i += 1) 
		if (!parse_arg(tar, argv[i], argc))
			tar = NULL;
	return tar;
}

// Process and returns status of archive creation/extraction
int				ft_tar(int argc, char *argv[])
{
	t_tar		*tar = init_tar(argc, argv);
	
	// printf(">> tar.files[0] : %s\n", tar->files[0]);
	return is_extract(tar) ? unarchive(tar) : archive(tar, argc, argv);
}
