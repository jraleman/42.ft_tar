/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archive.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 04:02:02 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/27 04:02:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARCHIVE_H
# define FT_ARCHIVE_H

/*
** Header files dependencies.
*/

# include <stdio.h>
# include <stdlib.h>

/*
** Read block size.
** Used 512 bytes to copy tar's block size. :)
** Source: http://www.gnu.org/software/tar/manual/html_node/Blocking.html
*/

# define BLOCK_SIZE		(512)

/*
** Metadata structure (linked-list)
*/

struct					s_metadata
{
	FILE				*fptr;
	char				*fname;
	int					size;
	int					nsize;
	int					ssize;
	struct s_metadata	*next;
}						t_metadata;

/*
** ft_archive prototype
*/

int						ft_archive(int count, char const *names[]);

#endif
