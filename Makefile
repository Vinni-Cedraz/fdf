# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/16 03:16:40 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf.a
NAME_BONUS = fdf_bonus.a
EXECUTABLE = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx -I$(PRNTF_PATH)includes -Iincludes -g
MLX = mlx/libmlx_Linux.a
LIBFT_PATH = lib/ft_printf_libft/libft/
PRNTF_PATH = lib/ft_printf_libft/
ARCHIVE_FROM_LIBFT = $(LIBFT_PATH)*.a
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
  			parse_map \
			rotate_map \
			  close_win \
			  render_map \
			     colorize \
	           render_line \
				   deal_key \
	          open_win_n_img \
	                     main \

BONUS_SRCS = put_pixel_img_bns \
				  parse_map_bns \
				  rotate_map_bns \
				  	 blackout_bns \
					 close_win_bns \
				     render_map_bns \
					    colorize_bns \
					  render_line_bns \
				    open_win_n_img_bns \
							   main_bns \
						     zoom_events \
	        translation_movements_and_esc \

SRCS_FROM_MLX = mlx_init \
	       mlx_new_window \
		     mlx_new_image \
		  mlx_get_data_addr \
	 mlx_put_image_to_window \
		   mlx_destroy_window \
		     mlx_destroy_image \

SRCS_FROM_LIBFT =  ft_memchr \
		    		ft_numlen \
		     		 ft_strchr \
					  ft_strlen \
					   ft_memcpy \
					   ft_memmove \
						 ft_memset \
						  ft_strdup \
						  ft_strlcpy \
						  ft_free_arr \
					      ft_atoi_base \
					    ft_word_counter \
					  		   ft_calloc \
							   ft_strlcat \
								   ft_atoi \
								   ft_split \
								  ft_strjoin \
								    ft_substr \

SRCS_FROM_LIBFT_TO_BONUS = ft_memchr \
							ft_numlen \
							 ft_strchr \
							  ft_strlen \
							   ft_memcpy \
							   ft_memmove \
								 ft_memset \
								  ft_strdup \
								  ft_strlcpy \
								  ft_free_arr \
								  ft_atoi_base \
								ft_word_counter \
									   ft_calloc \
									   ft_strlcat \
										   ft_atoi \
										   ft_split \
										  ft_strjoin \
											ft_substr \
											ft_strncmp \

################ MANDATORY VARIABLES ################
SRCS_PATH = srcs/srcs_mandatory/
OBJS_PATH = objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs_fdf/
OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))
################ BONUS VARIABLES ################
BONUS_SRCS_PATH = srcs/srcs_bonus/
BONUS_OBJS_PATH = objs_bonus/
BONUS_OBJS = $(patsubst %, $(BONUS_OBJS_PATH)%.o, $(BONUS_SRCS))
BONUS_MOD_OBJ = $(shell find $(BONUS_OBJS_PATH)*.o -newer $(NAME_BONUS))
################# MANDATORY RULES #################

all: $(NAME)

make_mlx:
	@./_mlx_/cp
	@make -C mlx --no-print-directory

make_libft:
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory

make_work_in_progress:
	@make bonus -C $(LIBFT_PATH) --no-print-directory
	@make -C $(PRNTF_PATH) --no-print-directory

$(NAME): $(OBJS) make_mlx make_work_in_progress
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
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
		printf "ar -rsc $(NAME) $(OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@printf "\n$(YELLOW)Creating Executable...$(DEF_COLOR)\n";
	$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME) $(MLX) $(PRNTF_PATH)libftprintf.a $(ARCHIVE_FROM_LIBFT) -o $(EXECUTABLE)
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

################# BONUS RULES #################

bonus: $(NAME_BONUS)

make_libft_for_bonus:
	@make srcs_to_fdf_bonus -C $(LIBFT_PATH) --no-print-directory
	@make -C $(PRNTF_PATH) --no-print-directory

$(NAME_BONUS): $(BONUS_OBJS) make_mlx make_work_in_progress make_libft_for_bonus
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(BONUS_MOD_OBJ); do \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_BONUS) $$file\n"; \
		ar -rsc $(NAME_BONUS) $$file; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	done
	@for file in $(BONUS_SRCS); do \
		if [[ -z "$$(nm $(NAME_BONUS) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_BONUS) $(BONUS_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_BONUS) $(BONUS_OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@printf "\n$(YELLOW)Creating Executable...$(DEF_COLOR)\n";
	$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME_BONUS) $(MLX) $(PRNTF_PATH)libftprintf.a $(ARCHIVE_FROM_LIBFT) -o $(EXECUTABLE)
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)\n"

$(BONUS_OBJS_PATH)%.o: $(BONUS_SRCS_PATH)%.c
	@mkdir -p $(BONUS_OBJS_PATH)
	@make BONUS_LOOP --no-print-directory

BONUS_LOOP:
	@for file in $(BONUS_SRCS); do \
		if [ $(BONUS_SRCS_PATH)$$file.c -nt $(BONUS_OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[$(NAME_BONUS)]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(BONUS_SRCS_PATH)$$file.c -o $(BONUS_OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(BONUS_SRCS_PATH)$$file.c -o $(BONUS_OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done

################# CLEANING RULES #################

clean:
	@make clean -C mlx --no-print-directory
	@make clean_fdf -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(PRNTF_PATH) --no-print-directory
	@rm -rf $(OBJS_PATH)
	@rm -rf $(BONUS_OBJS_PATH)
	@rm -f vgcore*
	@rm -f a.out

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(EXECUTABLE)
	@make fclean -C $(PRNTF_PATH) --no-print-directory
	@rm -f mlx/*.a

re: fclean all

