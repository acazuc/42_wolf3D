/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 07:51:29 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/30 08:57:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "env.h"

void	draw(t_env *env);
void	env_init(t_env *env);
void	error_quit(char *error_message);
int		key_listener(int key, void *data);
int		expose_listener(void *data);
void	map_init(t_env *env);
void	move_forward(t_env *env);
void	move_backward(t_env *env);
void	pixel_put(t_env *env, int x, int y, unsigned int color);
void	window_init(t_env *env);

#endif
