/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:41:03 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 11:03:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_init(t_env *env)
{
	int		y;
	int		x;

	env->map->width = 11;
	env->map->height = 11;
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
	x = 0;
	while (x < env->map->width)
	{
		env->map->data[0][x] = '#';
		env->map->data[env->map->height - 1][x] = '#';
		x++;
	}
	x = 0;
	while (x < env->map->height)
	{
		env->map->data[x][0] = '#';
		env->map->data[x][env->map->width - 1] = '#';
		x++;
	}
	env->map->data[1][1] = '#';
	env->map->data[1][4] = '#';
	env->map->data[1][6] = '#';
	env->map->data[1][9] = '#';

	env->map->data[3][3] = '#';
	env->map->data[3][5] = '#';
	env->map->data[3][7] = '#';

	env->map->data[4][3] = '#';
	env->map->data[4][5] = '#';
	env->map->data[4][7] = '#';

	env->map->data[5][3] = '#';
	env->map->data[5][7] = '#';

	env->map->data[6][1] = '#';
	env->map->data[6][9] = '#';

	env->map->data[7][3] = '#';
	env->map->data[7][7] = '#';

	env->map->data[8][3] = '#';
	env->map->data[8][5] = '#';
	env->map->data[8][7] = '#';

	env->map->data[9][3] = '#';
	env->map->data[9][5] = '#';
	env->map->data[9][7] = '#';

	env->map->data[10][1] = '#';
	env->map->data[10][4] = '#';
	env->map->data[10][6] = '#';
	env->map->data[10][9] = '#';
}
