# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/03 22:48:51 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I mlx -I libft -I includes
MLX = mlx/libmlx.a
LIBFT = libft/libft_fdf.a
# these are the flags mlx needs to compile on linux:
MLXFLAGS = -lXext -lX11 -lm
# Colors
RED    	  	=  \033[0;91m
GRAY      	=   \033[0;37m
CYAN      	=    \033[0;96m
WHITE     	=     \033[0;97m
GREEN     	=      \033[0;92m
YELLOW      =       \033[0;93m
MAGENTA     =        \033[0;95m
DEF_COLOR   =         \033[0;39m

SRCS = main \
	   open_win_n_img \
	   render_square \
	   render_line \
	   put_pixel_img \
	   event_handlers \

LIBFT_SRCS = ft_memchr \
			 ft_strlen \
			 ft_memcpy \
			 ft_strdup \
			 ft_strjoin \
			 ft_gnl \
		
SRCS_PATH = srcs/
LIBFT_PATH = libft/
OBJS_PATH = objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs_fdf/

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@make -C mlx --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJS) : $(SRCS_PATH)*.c
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory
	@mkdir -p $(OBJS_PATH)
	@for file in $(SRCS); do \
		printf "$(CYAN)Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o; \
		printf "$(GRAY)$(CC) $(CFLAGS) -c $$file.c -o $$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file$(DEF_COLOR) $(GREEN)OK$(DEF_COLOR)\n"; \
	done
	@printf "$(CYAN)All files compiled$(DEF_COLOR)\n"

clean:
	rm -rf $(OBJS_PATH)
	@make -C libft clean --no-print-directory
	@make -C mlx clean --no-print-directory
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)

re: fclean all
