# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/09/27 12:02:09 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = wolf3d.c \
			draw.c \
			env_init.c \
			error_quit.c \
			event_listener.c \
			movements.c \
			pixel_put.c \
			window_init.c \
			map_load.c \
			file_length.c \
			get_file_content.c \
			place_player.c \
			put_fps.c \
			epoch_millis.c \
			color_mult.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
