/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:01:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 12:49:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	place_player(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
		{
			if (env->map->data[y][x] == '1')
			{
				env->position->x = x + .5;
				env->position->y = y + .5;
				return ;
			}
		}
	}
	error_quit("No valid place on map");
}
