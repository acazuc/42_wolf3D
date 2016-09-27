/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:46:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/02 15:44:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	window_init(t_env *env)
{
	int		loul;

	env->window->width = 1280;
	env->window->height = 720;
	env->window->fov = 60;
	env->window->z_far = 30;
	if (!(env->window->mlx = mlx_init()))
		error_quit("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width, env->window->height
					, "acazuc's wolf3D")))
		error_quit("Failed to create window");
	env->window->bpp = 3 * 8;
	env->window->endian = 1;
	loul = env->window->width * env->window->bpp / 8;
	if (!(env->window->img = mlx_new_image(env->window->mlx, env->window->width
					, env->window->height)))
		error_quit("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &loul, &(env->window->endian))))
		error_quit("Failed to to get image data");
}
