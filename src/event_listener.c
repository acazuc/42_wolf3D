/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:10:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 15:46:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		rotate_left(t_env *env)
{
	double		old_dir_x;
	double		old_plane_x;
	double		cos_val;
	double		sin_val;

	cos_val = cos(2.5 / 180. * M_PI);
	sin_val = sin(2.5 / 180. * M_PI);
	old_dir_x = env->direction->x;
	env->direction->x = old_dir_x * cos_val - env->direction->y * sin_val;
	env->direction->y = old_dir_x * sin_val + env->direction->y * cos_val;
	old_plane_x = env->plane_x;
	env->plane_x = old_plane_x * cos_val - env->plane_y * sin_val;
	env->plane_y = old_plane_x * sin_val + env->plane_y * cos_val;
}

static void		rotate_right(t_env *env)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_val;
	double	sin_val;

	cos_val = cos(-2.5 / 180. * M_PI);
	sin_val = sin(-2.5 / 180. * M_PI);
	old_dir_x = env->direction->x;
	env->direction->x = old_dir_x * cos_val - env->direction->y * sin_val;
	env->direction->y = old_dir_x * sin_val + env->direction->y * cos_val;
	old_plane_x = env->plane_x;
	env->plane_x = old_plane_x * cos_val - env->plane_y * sin_val;
	env->plane_y = old_plane_x * sin_val + env->plane_y * cos_val;
}

int				loop_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	if (env->left)
		rotate_left(env);
	if (env->right)
		rotate_right(env);
	if (env->up)
		move_forward(env);
	if (env->down)
		move_backward(env);
	if (epoch_millis() - env->last_time >= 1000)
	{
		env->fps = env->tmp_fps;
		env->last_time = epoch_millis();
		env->tmp_fps = 0;
	}
	env->tmp_fps++;
	draw(env);
	return (0);
}

int				key_press_listener(int key, void *data)
{
	t_env		*env;

	env = (t_env*)data;
	if (key == 53)
		exit(1);
	else if (key == 123 || key == 0)
		env->left = 1;
	else if (key == 124 || key == 2)
		env->right = 1;
	else if (key == 13 || key == 126)
		env->up = 1;
	else if (key == 1 || key == 125)
		env->down = 1;
	return (0);
}

int				key_release_listener(int key, void *data)
{
	t_env		*env;

	env = (t_env*)data;
	if (key == 53)
		exit(1);
	else if (key == 123 || key == 0)
		env->left = 0;
	else if (key == 124 || key == 2)
		env->right = 0;
	else if (key == 13 || key == 126)
		env->up = 0;
	else if (key == 1 || key == 125)
		env->down = 0;
	return (0);
}
