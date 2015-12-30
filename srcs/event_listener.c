/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:10:06 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 08:57:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_listener(int key, void *data)
{
	t_env	*env;

	env = (t_env*)data;
	ft_putstr("Key event: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(1);
	else if (key == 123)
	{
		double old_dir_x = env->direction->x;
		env->direction->x = env->direction->x * cos(5. / 360 * 2 * M_PI)
			- env->direction->y * sin(5. / 360 * 2 * M_PI);
		env->direction->y = old_dir_x * sin(5. / 360 * 2 * M_PI)
			+ env->direction->y * cos(5. / 360 * 2 * M_PI);
		double old_plane_x = env->plane_x;
		env->plane_x = env->plane_x * cos(5. / 360 * 2 * M_PI)
			- env->plane_y * sin(5. / 360 * 2 * M_PI);
		env->plane_y = old_plane_x * sin(5. / 360 * 2 * M_PI)
			+ env->plane_y * cos(5. / 360 * 2 * M_PI);
	}
	else if (key == 124)
	{
		double old_dir_x = env->direction->x;
		env->direction->x = env->direction->x * cos(-5. / 360 * 2 * M_PI)
			- env->direction->y * sin(-5. / 360 * 2 * M_PI);
		env->direction->y = old_dir_x * sin(-5. / 360 * 2 * M_PI)
			+ env->direction->y * cos(-5. / 360 * 2 * M_PI);
		double old_plane_x = env->plane_x;
		env->plane_x = env->plane_x * cos(-5. / 360 * 2 * M_PI)
			- env->plane_y * sin(-5. / 360 * 2 * M_PI);
		env->plane_y = old_plane_x * sin(-5. / 360 * 2 * M_PI)
			+ env->plane_y * cos(-5. / 360 * 2 * M_PI);
	}
	else if (key == 13)
		move_forward(env);
	else if (key == 1)
		move_backward(env);
	draw(env);
	return (0);
}

int		expose_listener(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	draw(env);
	return (0);
}
