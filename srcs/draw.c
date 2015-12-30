/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:13:54 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 09:11:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray	*get_ray(t_env *env, int x)
{
	double 	camera_x = 2. * x / env->window->width * 1;
	double	ray_pos_x = env->position->x;
	double	ray_pos_y = env->position->y;
	double	ray_dir_x = env->direction->x + env->plane_x * camera_x;
	double	ray_dir_y = env->direction->y + env->plane_y * camera_x;
	int		map_x = (int)ray_pos_x;
	int		map_y = (int)ray_pos_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x = sqrt(1 + pow(ray_dir_y, 2) / pow(ray_dir_x, 2));
	double	delta_dist_y = sqrt(1 + pow(ray_dir_x, 2) / pow(ray_dir_y, 2));
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit = 0;
	int		side = 0;
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (ray_pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - ray_pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - ray_pos_y) * delta_dist_y;
	}
	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			if (step_x < 0)
				side = 0;
			else
				side = 1;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			if (step_y < 0)
				side = 2;
			else
				side = 3;
		}
		if (map_x < 0 || map_x >= env->map->width || map_y < 0
				|| map_y >= env->map->height || env->map->data[map_y][map_x] != ' ')
			hit = 1;
	}
	if (side == 0 || side == 1)
		perp_wall_dist = fabs((map_x - ray_pos_x + (1 - step_x) / 2) / ray_dir_x);
	else
		perp_wall_dist = fabs((map_y - ray_pos_y + (1 - step_y) / 2) / ray_dir_y);
	t_ray ray;
	ray.length = abs((int)(env->window->height / perp_wall_dist));
	if (ray.length > env->window->height)
		ray.length = env->window->height;
	if (side == 0)
		ray.color = 0xFF0000;
	else if (side == 1)
		ray.color = 0x00FF00;
	else if (side == 2)
		ray.color = 0x0000FF;
	else
		ray.color = 0xFFFF00;
	t_ray *loul = &ray;
	return (loul);
}

void	draw(t_env *env)
{
	t_ray	*ray;
	int		x;
	int		y;

	x = 0;
	while (x < env->window->width)
	{
		ray = get_ray(env, x);
		y = -1;
		while (++y < env->window->height / 2 - ray->length / 2)
			pixel_put(env, x, y, CEIL);
		while (++y < env->window->height / 2 + ray->length / 2)
			pixel_put(env, x, y, ray->color);
		while (++y < env->window->height)
			pixel_put(env, x, y, FLOOR);
		x++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window, env->window->img, 0, 0);
}
