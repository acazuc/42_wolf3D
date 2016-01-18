/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:44:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 14:43:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		error_quit("./wolrf3d map_name");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env struct");
	env_init(env);
	map_load(env->map, av[1]);
	window_init(env);
	mlx_key_hook(env->window->mlx_window, &key_listener, env);
	mlx_expose_hook(env->window->mlx_window, &expose_listener, env);
	mlx_loop(env->window->mlx);
}
