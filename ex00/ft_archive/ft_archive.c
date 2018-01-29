/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:51:01 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/26 18:51:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_archive.h"

/*
** ...
*/

static void	file_expand(FILE *fp, size_t amount)
{
	while (amount)
	{
		fputc(0, fp);
		amount -= 1;
	}
	return ;
}

/*
** ...
*/

static int	add_files(FILE *tar, char *name)
{
	FILE	*input;
	size_t	index;
	size_t	offset;

	index = ftell(tar);
	offset = index % BLOCK_SIZE;
	if (offset != 0)
		file_expand(tar, BLOCK_SIZE - offset);
	index = ftell(tar);
	file_expand(tar, sizeof(t_mdata));
	if (!(input = fopen(name, "rb")))
		return (-1);

	return (0);
}

/*
** Add multiple files to a single archive.
*/

int			ft_archive(FILE *tar, char *names[], int count)
{
	int		i;
	int		ret;

	ret = 0;
	if (!tar)
		return (-1);
	i = 2;
	while (i < count)
	{
		if (add_files(tar, names[i]) != 0)
			break ;
		i += 1;
	}
	file_expand(tar, 1024);
	fclose(tar);
	return (i == count ? 0 : -1);
}
