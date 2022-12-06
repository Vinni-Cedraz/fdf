# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/05 19:34:09 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf.a
EXECUTABLE = fdf
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I mlx -I libft -I includes
MLX = mlx/libmlx.a
SRCS_TO_FDF = libft/srcs_to_fdf.a
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

SRCS = put_pixel_img \
	   render_square \
	   render_line \
	   event_handlers \
	   open_win_n_img \
	   main \

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
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))

all: $(NAME)

make_mlx:
	@make -C mlx --no-print-directory

make_libft:
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) make_mlx make_libft
	@printf "\n$(YELLOW)Linking Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME) $$file\n"; \
		ar -rsc $(NAME) $$file; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME) $$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME) $(MLX) $(SRCS_TO_FDF) -o $(EXECUTABLE)
	@printf "\n$(YELLOW)Creating Executable...$(DEF_COLOR)\n";
	@printf "\n$(CYAN)$(CC) $(GRAY)$(MLXFLAGS) $(CFLAGS) $(RED)$(NAME) $(GRAY)mlx/$(RED)libmlx.a $(GRAY)libft/$(RED)srcs_to_fdf.a $(WHITE)-o $(GREEN)$(EXECUTABLE)$(DEF_COLOR)\n"
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)\n"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP: 
	@for file in $(SRCS); do \
		if [ $(SRCS_PATH)$$file.c -nt $(OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[$(NAME)]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done

clean:
	@make clean -C mlx --no-print-directory
	@make clean_fdf -C $(LIBFT_PATH) --no-print-directory
	@rm -rf $(OBJS_PATH)
	@rm -f vgcore*
	@rm -f a.out

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXECUTABLE)
	@make -C $(LIBFT_PATH) fclean_fdf --no-print-directory
	@rm -f mlx/*.a

re: fclean all
