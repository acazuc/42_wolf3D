/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:14:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 13:15:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_fps(t_env *env)
{
	char	*fps;

	if ((fps = ft_itoa(env->fps)))
	{
		mlx_string_put(env->window->mlx, env->window->mlx_window
				, 11, 11, 0x000000, fps);
		mlx_string_put(env->window->mlx, env->window->mlx_window
				, 10, 10, 0xFF0000, fps);
		free(fps);
	}
}
