/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:54:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 13:04:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "window.h"
# include "vector.h"
# include "map.h"

typedef struct			s_env
{
	t_vector			*position;
	t_vector			*direction;
	t_window			*window;
	t_map				*map;
	double				plane_x;
	double				plane_y;
	int					left;
	int					right;
	int					up;
	int					down;
	int					fps;
	int					tmp_fps;
	long				last_time;
}						t_env;

#endif
