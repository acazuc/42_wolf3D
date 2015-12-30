/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:44:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 09:35:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env struct");
	env_init(env);
	window_init(env);
	map_init(env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_loop(env->window->mlx);
}
