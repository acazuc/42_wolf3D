/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:59:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 12:14:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		color_mult(int c, float p)
{
	return (((int)(((c >> 24) & 0xff) * p) << 24)
			| ((int)(((c >> 16) & 0xff) * p) << 16)
			| ((int)(((c >> 8) & 0xff) * p) << 8)
			| ((int)(((c) & 0xff) * p)));
}
