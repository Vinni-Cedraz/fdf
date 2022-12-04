# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/04 20:21:37 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I mlx -I libft -I includes
MLX = mlx/libmlx.a
LIBFT = libft/srcs_to_fdf.a
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

FDF_SRCS = ft_memchr \
		   ft_strchr \
			 ft_strlen \
			 ft_memcpy \
			 ft_memmove \
			 ft_memset \
			 ft_strdup \
			 ft_strlcpy \
			 ft_free_arr \
			 ft_word_counter \
			 ft_calloc \
		     ft_strlcat \
			 ft_atoi \
			 ft_split \
			 ft_strjoin \
			 ft_substr \

SRCS_PATH = srcs/
LIBFT_PATH = libft/
OBJS_PATH = objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs_fdf/

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))

all: $(NAME)

make_mlx:
		@make -C mlx --no-print-directory

make_libft:
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) make_mlx make_libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP: 
	@for i in $(SRCS); do \
		$(CC) $(CFLAGS) -c $(SRCS_PATH)$$i.c -o $(OBJS_PATH)$$i.o; \
	done

clean:
	@make clean -C mlx --no-print-directory
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@rm -rf $(OBJS_PATH)
	@printf "$(RED)$(OBJS_PATH)$(DEF_COLOR) $(GREEN)deleted$(DEF_COLOR)\n"
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)

re: fclean all
