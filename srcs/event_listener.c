/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:10:06 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 09:42:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		rotate_left(t_env *env)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = env->direction->x;
	env->direction->x = env->direction->x * cos(5. / 360. * 2 * M_PI)
		- env->direction->y * sin(5. / 360. * 2 * M_PI);
	env->direction->y = old_dir_x * sin(5. / 360. * 2 * M_PI)
		+ env->direction->y * cos(5. / 360. * 2 * M_PI);
	old_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos(5. / 360. * 2 * M_PI)
		- env->plane_y * sin(5. / 360. * 2 * M_PI);
	env->plane_y = old_plane_x * sin(5. / 360 * 2 * M_PI)
		+ env->plane_y * cos(5. / 360. * 2 * M_PI);
}

static void		rotate_right(t_env *env)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = env->direction->x;
	env->direction->x = env->direction->x * cos(-5. / 360. * 2 * M_PI)
		- env->direction->y * sin(-5. / 360. * 2 * M_PI);
	env->direction->y = old_dir_x * sin(-5. / 360. * 2 * M_PI)
		+ env->direction->y * cos(-5. / 360. * 2 * M_PI);
	old_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos(-5. / 360. * 2 * M_PI)
		- env->plane_y * sin(-5. / 360. * 2 * M_PI);
	env->plane_y = old_plane_x * sin(-5. / 360 * 2 * M_PI)
		+ env->plane_y * cos(-5. / 360. * 2 * M_PI);
}

int				key_listener(int key, void *data)
{
	t_env		*env;

	env = (t_env*)data;
	if (key == 53)
		exit(1);
	else if (key == 123)
		rotate_left(env);
	else if (key == 124)
		rotate_right(env);
	else if (key == 13)
		move_forward(env);
	else if (key == 1)
		move_backward(env);
	draw(env);
	return (0);
}

int				expose_listener(void *data)
{
	t_env		*env;

	env = (t_env*)data;
	draw(env);
	return (0);
}
