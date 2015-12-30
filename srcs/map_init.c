/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:41:03 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 08:44:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <unistd.h>

void	map_init(t_env *env)
{
	int		y;
	int		x;

	env->map->width = 20;
	env->map->height = 20;
	if (!(env->map->data = malloc(sizeof(*(env->map->data))
					* env->map->height)))
		error_quit("Failed to malloc map (height)");
	y = 0;
	while (y < env->map->height)
	{
		if (!(env->map->data[y] = malloc(sizeof(**(env->map->data))
						* env->map->width)))
			error_quit("Failed tp mallloc map (width)");
		x = 0;
		while (x < env->map->width)
		{
			env->map->data[y][x] = ' ';
			x++;
		}
		y++;
	}
	int i = 0;
	while (i < env->map->width)
	{
		env->map->data[0][i] = '#';
		env->map->data[env->map->height - 1][i] = '#';
		i++;
	}
	i = 0;
	while (i < env->map->height)
	{
		env->map->data[i][0] = '#';
		env->map->data[i][env->map->width - 1] = '#';
		i++;
	}
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			write(1, &(env->map->data[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
