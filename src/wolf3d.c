/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:44:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 11:08:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		error_quit("./wolf3d map_name");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env struct");
	env_init(env);
	map_load(env->map, av[1]);
	place_player(env);
	window_init(env);
	mlx_do_key_autorepeatoff(env->window->mlx);
	mlx_hook(env->window->mlx_window, 2, 1, &key_press_listener, env);
	mlx_hook(env->window->mlx_window, 3, 2, &key_release_listener, env);
	mlx_loop_hook(env->window->mlx, loop_listener, env);
	mlx_loop(env->window->mlx);
}
