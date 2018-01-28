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

// global variables
t_mdata *mhead = NULL, *current = NULL;

/*
** ...
*/

void		debug_metadata(t_mdata *mdata)
{
	printf("%s\n", mdata->name);
	printf("%p\n", mdata->fp);
	printf("%d\n", mdata->size);
	printf("%d\n", mdata->nsize);
	printf("%d\n\n", mdata->ssize);
	return ;
}


/*
**
--------------------------------------------------------------------------------
*/


/*
** Get size of the file pointer.
*/

static int	get_size(FILE *fp)
{
	int		size;

	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	return (size);
}

/*
** ...
*/

static int	add_metadata(char *name)
{
	FILE	*fp;
	char	tmp[255];
	t_mdata	*mdata;

	if (!(mdata = (t_mdata *)malloc(sizeof(t_mdata))))
		return (-1);
	bzero(tmp, 255);
	fp = fopen(name, "r+");
	mdata->name = strdup(name);
	mdata->fp = fp;
	mdata->size = get_size(fp);
	mdata->nsize = strlen(name);
	sprintf(tmp, "%d", mdata->size);
	mdata->ssize = strlen(tmp);
	mdata->next = NULL;

	// delete this
	if (mhead == NULL)
	{
		mhead = mdata;
		current = mdata;
	}
	else
	{
		current->next = mdata;
		current = mdata;
	}

	debug_metadata(current);

	free(tmp);
	fclose(fp);
	return (0);
}

/*
** Modifies data to conform with the input requirements of another function.
*/

static int	header_preprocessor(int count, char *names[])
{
	int		i;

	i = 2;
	while (i < count)
	{
		// add metadata
		// printf("%s\n", names[i]);
		add_metadata(names[i]);
		i += 1;
	}
	return (0);
}


/*
**
--------------------------------------------------------------------------------
*/


/*
** Compress multiple files to a single archive.
** Need to add metadata about the info of the files to the archive.
*/

int		ft_archive(int count, char *names[])
{
	// Create Header
	printf("Pre-processing files: %s\n", "--list of files--");
	printf("Collecting metadata...\n");
	header_preprocessor(count, names);
	printf("Compiling header information...\n");
	// header_compile();
	printf("Creating and writting header to archive...\n");
	// header_write();

	// read_block()

	// body_writer()

	// print_stats()
	return (0);
}
