/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:01:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 15:17:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	place_player(t_env *env)
{
	int		x;
	int		y;

	if (env->map->data[env->map->height / 2][env->map->width / 2] == ' ')
	{
		env->position->x = env->map->width / 2 + .5;
		env->position->y = env->map->height / 2 + .5;
		return ;
	}
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (env->map->data[y][x] == ' ')
			{
				env->position->x = x + .5;
				env->position->y = y + .5;
				return ;
			}
			x++;
		}
		y++;
	}
	error_quit("No valid place on map");
}
