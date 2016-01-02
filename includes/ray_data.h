/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:50:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:34:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_DATA_H
# define RAY_DATA_H

# include "ray.h"

typedef struct		s_ray_data
{
	t_ray			ray;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_ray_data;
#endif
