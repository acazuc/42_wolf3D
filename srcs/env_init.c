/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:34:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 12:55:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	env_init(t_env *env)
{
	if (!(env->position = malloc(sizeof(*env->position))))
		error_quit("Failed to malloc position struct");
	env->position->x = 3;
	env->position->y = 2;
	if (!(env->direction = malloc(sizeof(*env->direction))))
		error_quit("Failed to malloc rotation struct");
	env->direction->x = -1;
	env->direction->y = 0;
	if (!(env->window = malloc(sizeof(*env->window))))
		error_quit("Failed to malloc window struct");
	if (!(env->map = malloc(sizeof(*env->window))))
		error_quit("Failed to malloc map struct");
	env->last_time = epoch_millis();
	env->tmp_fps = 0;
	env->fps = 0;
	env->plane_x = 0;
	env->plane_y = 1;
	env->left = 0;
	env->right = 0;
	env->up = 0;
	env->down = 0;
}
