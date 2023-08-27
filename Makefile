# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:19:27 by vcedraz-          #+#    #+#              #
#    Updated: 2023/08/21 17:40:38 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = fdf.a
NAME_BONUS = fdf_bonus.a
EXECUTABLE = fdf
CFLAGS = -Wall -Wextra -Werror -O3 -pthread \
		 -I$(INC_LIBFT) \
		 -I$(INC_PRNTF) \
		 -I$(INC_CLASSES_METHODS) \
		 -I$(INC_LINKED_LIST) \
		 -I$(INC)
# MLX = mlx/libmlx_Linux.a
LIBFT_PATH = libs/ft_printf_libft/libft/
PRNTF_PATH = libs/ft_printf_libft/
LINKED_LIST_PATH = libs/linked_list_for_fdf/
LINKED_LIST_TOOLS = $(LINKED_LIST_PATH)linked_list_tools.a
INC_CLASSES_METHODS = includes/methods_and_classes_bonus/
INC_LIBFT = $(LIBFT_PATH)includes/
INC_PRNTF = $(PRNTF_PATH)includes/
INC_LINKED_LIST = $(LINKED_LIST_PATH)includes/
INC = includes
# INC_MLX = mlx/
MLXFLAGS = -L $(LIBFT_PATH) -lXext -lX11 -lm -lmlx

# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW          =  \033[0;93m
MAGENTA         =  \033[0;95m
DEF_COLOR       =  \033[0;39m

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

BONUS_SRCS = parse_map_bonus \
	     main_bonus \
	     data_initializer_bonus \
 	     define_rotation_matrices_bonus \
	     close_win_bonus \
	     render_map_bonus \
	     render_line_bonus \
	     draw_bonus \
	     deal_keys_bonus \
	     change_altitude_bonus \
	     calculate_default_scale_bonus \
	     assign_coordinates_bonus \
	     assign_hexcolor_bonus \
		 multi_threaded_iter \
	     multiply_two_matrices_bonus \
	     get_map_dimensions_bonus \
		 open_win_n_img_bonus \
	     initialize_lookup_structs_bonus \
	     rotate_five_bonus \
	     reverse_five_bonus \
	     zoom_bonus \
	     zoom_methods_bonus \
	     lookup_transition_methods_bonus \
	     loop_through_each_transition_method_bonus \
	     sphere_bonus \
	     get_xyz_range_bonus \
	     initialize_methods_bonus \
	     colorize_points_bonus \
	     set_hexcolor_bonus \
	     transpts_with_given_matrix_bonus \
	     draw_menu_bonus \
	     error_handlers_bonus \
	     restore_raw_state_bonus \
	     normalize_after_leaving_sphere_bonus \

SRCS_FROM_LIBFT =  ft_strnstr \
		   ft_swap \
		   ft_free_arr \
		   ft_free_arr_size \
		   ft_free_t_split \
		   ft_atoi_base \
		   ft_word_counter \
		   ft_strlen \
		   ft_gnl \
		   ft_ishexlow \
		   ft_ishexup \
		   ft_strtrim \
		   ft_calloc \
		   ft_atoi \
		   ft_memchr \
		   ft_split \
		   ft_strjoin \
		   ft_memcpy \
		   ft_strdup \
		   ft_lstnew \
		   ft_lstadd_back \
		   ft_lst_make_it_circular \
		   ft_lstcircular_free \
		   ft_putstr \
		   ft_bzero \


SRCS_FROM_LINKED_LIST_TOOLS = ft_lstpoint_back \
			      ft_lstpoint_new \
			      ft_lstpoint_free \
			      ft_lstpoint_front \
			      ft_lstpoint_getby_index \
			      ft_lstpoint_toarr \
			      ft_lstpoint_size \
				  ft_lstpoint_iter \
				  ft_lstpoint_iter_and_get \

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

make_libft:
	@make srcs_to_fdf -C $(LIBFT_PATH) --no-print-directory
	@make -C $(PRNTF_PATH) --no-print-directory


$(NAME): $(OBJS) make_libft
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                       \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(EXECUTABLE)$(DEF_COLOR)\n"; \
	$(CC) $(CFLAGS) $(NAME) $(PRNTF_PATH)libftprintf.a $(LIBFT_PATH)srcs_to_fdf.a $(MLXFLAGS) -o $(EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(NAME)$(DEF_COLOR)                                             \n";
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)                  \n";

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

make_libs_for_bonus:
	@make -C $(LINKED_LIST_PATH) --no-print-directory
	@make srcs_to_fdf_bonus -C $(LIBFT_PATH) --no-print-directory

$(NAME_BONUS): $(BONUS_OBJS) make_libs_for_bonus
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(BONUS_MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                    \r"; \
		ar -rsc $(NAME_BONUS) $$file; \
	done
	@for file in $(BONUS_SRCS); do \
		if [[ -z "$$(nm $(NAME_BONUS) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_BONUS) $(BONUS_OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                     \r"; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_BONUS)$(DEF_COLOR)                                             \n";
	@printf "$(CYAN)Creating $(EXECUTABLE)$(DEF_COLOR)\n"; \
	$(CC) $(CFLAGS) $(NAME_BONUS) $(LIBFT_PATH)srcs_to_fdf_bonus.a $(LINKED_LIST_TOOLS) $(MLXFLAGS) -o $(EXECUTABLE);
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)\n";

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

################# CLEAN RULES #################

clean:
	@make clean_fdf -C $(LIBFT_PATH) --no-print-directory
	@make clean_fdf_bonus -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(PRNTF_PATH) --no-print-directory
	@rm -rf $(OBJS_PATH)
	@rm -rf $(BONUS_OBJS_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f vgcore*
	@rm -f a.out

fclean: clean
	@rm -f $(EXECUTABLE)
	@make fclean -C $(PRNTF_PATH) --no-print-directory
	@make fclean_fdf -C $(LIBFT_PATH) --no-print-directory
	@make fclean_fdf_bonus -C $(LIBFT_PATH) --no-print-directory
	@make fclean -C $(LINKED_LIST_PATH) --no-print-directory

re: fclean all

bonus_re: fclean bonus
