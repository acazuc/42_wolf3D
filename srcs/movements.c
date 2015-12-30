/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:52:18 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 10:17:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		check_collision(t_env *env, double old_x, double old_y)
{
	if (env->position->x < 0 || env->position->x >= env->map->width) {
		env->position->x = old_x;
	}
	if (env->position->y < 0 || env->position->y >= env->map->height) {
		env->position->y = old_y;
	}
	if (env->map->data[(int)old_y][(int)env->position->x] == '#') {
		env->position->x = old_x;
	}
	if (env->map->data[(int)env->position->y][(int)old_x] == '#') {
		env->position->y = old_y;
	}
}

void			move_forward(t_env *env)
{
	double	old_x;
	double	old_y;

	old_x = env->position->x;
	old_y = env->position->y;
	env->position->x += env->direction->x / 3.;
	env->position->y += env->direction->y / 3.;
	check_collision(env, old_x, old_y);
}

void			move_backward(t_env *env)
{
	double	old_x;
	double	old_y;

	old_x = env->position->x;
	old_y = env->position->y;
	env->position->x -= env->direction->x / 3.;
	env->position->y -= env->direction->y / 3.;
	check_collision(env, old_x, old_y);
}
