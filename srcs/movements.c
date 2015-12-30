/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:52:18 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 09:08:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			move_forward(t_env *env)
{
	env->position->x += env->direction->x / 3.;
	env->position->y += env->direction->y / 3.;
}

void			move_backward(t_env *env)
{
	env->position->x -= env->direction->x / 3.;
	env->position->y -= env->direction->y / 3.;
}
