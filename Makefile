# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2023/01/18 20:15:23 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf.a
NAME_BONUS = fdf_bonus.a
NAME_WIP = wip.a
EXECUTABLE = fdf
CFLAGS = -Wall -Wextra -Werror -Imlx -I$(PRNTF_PATH)includes -Iincludes -g
MLX = mlx/libmlx_Linux.a
LIBFT_PATH = lib/ft_printf_libft/libft/
PRNTF_PATH = lib/ft_printf_libft/
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
			 close_win \
			 render_map \
			    colorize \
				     draw \
  define_rotation_matrices \
     linear_transformations \
		    data_initializer \
				     deal_key \
			     standard_scale\
	             open_win_n_img \
	                        main \

BONUS_SRCS = two_steps_to_isometry_bonus \
					      close_win_bonus \
					 colorize_points_bonus \
					        deal_keys_bonus \
					              draw_bonus \
					               main_bonus \
					           parse_map_bonus \
					           render_map_bonus \
					           render_line_bonus \
					 linear_transformations_bonus \
					define_rotation_matrices_bonus \
					         data_initializer_bonus \
					   calculate_default_scale_bonus \
					            change_altitude_bonus \
					                        zoom_bonus \

WIP_SRCS = parse_map_bonus \
		   main_bonus \
		   data_initializer_bonus \
		   define_rotation_matrices_bonus \
		   close_win_bonus \
		   two_steps_to_isometry_bonus \
		   linear_transformations_bonus \
		   render_map_bonus \
		   render_line_bonus \
		   zoom_bonus \
		   draw_bonus \
		   colorize_points_bonus \
		   deal_keys_bonus \
		   change_altitude_bonus \
		   calculate_default_scale_bonus \
		   get_altitude_range_bonus \
		   assign_coordinates_bonus \
		   get_and_assign_hexcolor_bonus \


SRCS_FROM_MLX = mlx_init \
	       mlx_new_window \
		     mlx_new_image \
		  mlx_get_data_addr \
	 mlx_put_image_to_window \
		   mlx_destroy_window \
		     mlx_destroy_image \

SRCS_FROM_LIBFT =  ft_strnstr \
				   	   ft_swap \
				  ft_free_t_map \
				 ft_free_t_split \
				     ft_atoi_base \
				   ft_word_counter \
				          ft_strlen \
					          ft_gnl \
					      ft_ishexlow \
					         ft_calloc \
					            ft_atoi \
							   ft_memchr \
					             ft_split \
							    ft_strjoin \
								  ft_memcpy \
								   ft_strdup \

SRCS_FROM_LIBFT_BONUS =  ft_strnstr \
						     ft_swap \
					    ft_free_t_map \
					   ft_free_t_split \
						   ft_atoi_base \
					     ft_word_counter \
							    ft_strlen \
							ft_special_gnl \
							    ft_ishexlow \
								   ft_calloc \
									  ft_atoi \
								     ft_memchr \
									   ft_split \
									  ft_strjoin \
									    ft_memcpy \
									     ft_strdup \

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
################ WIP VARIABLES #################
WIP_SRCS_PATH = srcs/srcs_bonus/
WIP_OBJS_PATH = objs_wip/
WIP_OBJS = $(patsubst %, $(WIP_OBJS_PATH)%.o, $(WIP_SRCS))
WIP_MOD_OBJ = $(shell find $(WIP_OBJS_PATH)*.o -newer $(NAME_WIP))
################# MANDATORY RULES #################

all: $(NAME)

make_mlx:
	@./_mlx_/cp.c
	@make -C mlx --no-print-directory

make_libft:
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory
	@make -C $(PRNTF_PATH) --no-print-directory


$(NAME): $(OBJS) make_mlx make_libft
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
	$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME) $(MLX) $(PRNTF_PATH)libftprintf.a $(LIBFT_PATH)srcs_to_fdf.a -o $(EXECUTABLE)
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

$(NAME_BONUS): $(BONUS_OBJS) make_mlx make_libft_for_bonus
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
	$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME_BONUS) $(MLX) $(LIBFT_PATH)srcs_to_fdf_bonus.a -o $(EXECUTABLE)
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

################# WIP RULES #################

wip: $(NAME_WIP)
	
make_work_in_progress:
	@make bonus -C $(LIBFT_PATH) --no-print-directory
	@make -C $(PRNTF_PATH) --no-print-directory

$(NAME_WIP): $(WIP_OBJS) make_mlx make_work_in_progress
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(WIP_MOD_OBJ); do \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_WIP)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_WIP) $$file\n"; \
		ar -rsc $(NAME_WIP) $$file; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	done
	@for file in $(WIP_SRCS); do \
		if [[ -z "$$(nm $(NAME_WIP) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_WIP) $(WIP_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_WIP)$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_WIP) $(WIP_OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@printf "\n$(YELLOW)Creating Executable...$(DEF_COLOR)\n";
	$(CC) $(MLXFLAGS) $(CFLAGS) $(NAME_WIP) $(MLX) $(PRNTF_PATH)libftprintf.a $(LIBFT_PATH)libft_bonus.a -o $(EXECUTABLE)
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)\n"

$(WIP_OBJS_PATH)%.o: $(WIP_SRCS_PATH)%.c
	@mkdir -p $(WIP_OBJS_PATH)
	@make WIP_LOOP --no-print-directory

WIP_LOOP:
	@for file in $(WIP_SRCS); do \
		if [ $(WIP_SRCS_PATH)$$file.c -nt $(WIP_OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[$(NAME_WIP)]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(WIP_SRCS_PATH)$$file.c -o $(WIP_OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(WIP_SRCS_PATH)$$file.c -o $(WIP_OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done

################# CLEAN RULES #################

clean:
	@make clean -C mlx --no-print-directory
	@make clean_fdf -C $(LIBFT_PATH) --no-print-directory
	@make clean_fdf_bonus -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(PRNTF_PATH) --no-print-directory
	@rm -rf $(WIP_OBJS_PATH)
	@rm -rf $(OBJS_PATH)
	@rm -rf $(BONUS_OBJS_PATH)
	@rm -f vgcore*
	@rm -f a.out

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(NAME_WIP)
	@rm -f $(EXECUTABLE)
	@make fclean -C $(PRNTF_PATH) --no-print-directory
	@make fclean_fdf -C $(LIBFT_PATH) --no-print-directory
	@make fclean_fdf_bonus -C $(LIBFT_PATH) --no-print-directory
	@rm -f mlx/*.a

re: fclean all
