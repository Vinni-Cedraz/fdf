# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/03 13:17:42 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf
CC = cc
CFLAGS = -O3 -Wall -Wextra -Werror -I mlx -I libft -I includes
MLX = mlx/libmlx.a
LIBFT = libft/libft.a
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
	   open_window \
	   render_square \
	   render_line \
	   put_pixel_img \
	   event_handlers \
	   
		
SRCS_PATH = srcs/
OBJS_PATH = objs/

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@make -C mlx --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJS) : $(SRCS_PATH)*.c
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

fclean: clean
	@rm -f $(NAME)

re: fclean all
