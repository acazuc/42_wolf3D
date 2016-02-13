/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 07:51:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/12 13:15:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

void	draw(t_env *env);
void	env_init(t_env *env);
void	error_quit(char *error_message);
int		key_press_listener(int key, void *data);
int		key_release_listener(int key, void *data);
int		loop_listener(void *data);
void	map_init(t_env *env);
void	move_forward(t_env *env);
void	move_backward(t_env *env);
void	pixel_put(t_env *env, int x, int y, unsigned int color);
void	window_init(t_env *env);
void	map_load(t_map *map, char *file);
int		file_length(char *file);
char	*get_file_content(char *file);
void	place_player(t_env *env);
long	epoch_millis(void);
void	put_fps(t_env *env);

#endif
