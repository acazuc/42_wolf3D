/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:00:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 14:29:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		file_length(char *file)
{
	char	*buffer;
	int		readed;
	int		size;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open map file");
	if (!(buffer = malloc(sizeof(*buffer) * 100000)))
		error_quit("Failed to malloc buffer");
	size = 0;
	while ((readed = read(fd, buffer, 100000)) > 0)
		size += readed;
	close(fd);
	free(buffer);
	if (readed == -1)
		error_quit("Failed to read map file");
	return (size);
}
