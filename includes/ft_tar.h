/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 04:02:02 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/27 04:02:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAR_H
# define FT_TAR_H

// Header files dependencies.
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>

// Read block size.
// Used 512 bytes to copy tar's block size. :)
// Source: http://www.gnu.org/software/tar/manual/html_node/Blocking.html
# define BLOCK_SIZE	512

// Max file name length
# define NAME_SIZE	255
# define ERR_CODE	-1
# define OK_CODE	0
# define ERR_USAGE	1
# define ERR_CREATE	2
# define ERR_OPEN	3

// Boolean stuff
# define FALSE		0
# define TRUE		1

// Flags
# define VRB_FLG	"-v"
# define EXT_FLG	"-x"
# define CRT_FLG	"-c"
# define FLG_NUM	3

// Metadata structure
typedef struct	s_mdata
{
	char		name[NAME_SIZE];
	FILE		*fp;
	int			size;
	int			nsize;
	int			ssize;
	struct		mdata *next;
}				t_mdata;

typedef struct s_flags
{
	int			x;
	int			v;
	int			c;
}				t_flags;

typedef struct s_tar
{
	char		**files;
	char		block[BLOCK_SIZE];
	char		stsize[5];
	char		shsize[100];
	int			rsize;
	int			tnsize;
	int			tssize;
	int			hsize;
	int			scount;
	int			fcount;
	FILE		*fpar;		// <- maybe won't use
	FILE		*fp;		// <- maybe won't use
	t_mdata		*mhead;		// <- maybe won't use
	t_mdata		*current;	// <- maybe won't use
	t_flags		flag;
}				t_tar;

// Function prototypes
int			is_file(char *arg);
int			is_flag(char *arg);
int			archive_error(void);
int			is_conflict(t_tar *tar);
int			usage_error(char *name);
char		**get_flags(char *flag);
size_t		get_filesize(char *filename);
int			ft_tar(int argc, char *argv[]);
int			print_verbose(t_tar *tar, char *msg);
void		expand_file(FILE *fp, size_t amount);
int			archive(t_tar *tar, int total, char *files[]);
int			unarchive(t_tar *tar, int total, char *files[]);

#endif
