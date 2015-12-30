/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 08:54:15 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 09:28:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

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
}						t_env;

#endif
