/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoch_millis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:59:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 12:55:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

long	epoch_millis(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
