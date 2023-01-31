# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:33:51 by vcedraz-          #+#    #+#              #
#    Updated: 2023/01/31 16:13:31 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ VARIABLES ################

NAME = linked_list_tools.a
INC_LIBFT = ../ft_printf_libft/libft/
INC_PRINTF = ../ft_printf_libft/includes/
INC_FDF = ../../includes/
INC_METHODS = ../../includes/methods_and_classes_bonuss/
INC = includes/
CFLAGS = -Wall -Wextra -Werror -O3\
		 -I$(INC_LIBFT) \
		 -I$(INC_PRINTF) \
		 -I$(INC_FDF) \
		 -I$(INC) \
		 -I$(INC_METHODS)
SRCS_PATH = srcs/
OBJS_PATH = objs/
OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))
# Colors
RED    	  	=  \033[0;91m
GRAY      	=   \033[0;37m
CYAN      	=    \033[0;96m
WHITE     	=     \033[0;97m
GREEN     	=      \033[0;92m
YELLOW      =       \033[0;93m
MAGENTA     =        \033[0;95m
DEF_COLOR   =         \033[0;39m

SRCS = ft_lstpoint_new \
	   ft_lstpoint_back \
	     ft_lstpoint_dup \
		 ft_lstpoint_free \
		 ft_lstpoint_front \
    ft_lstpoint_getby_index \
			ft_lstpoint_size \
			ft_lstpoint_toarr \

################# COMPILING AND LINKING RULES #################

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(OBJS); do \
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

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP:
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
			printf "$(CYAN)Compiling $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)\n"; \
			printf "cc $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
		fi; \
	done

################# CLEAN RULES #################

clean:
	@printf "$(RED)Deleting linked_list_tools Objects...$(DEF_COLOR)\n";
	@rm -rf $(OBJS_PATH)

fclean: clean
	@printf "$(RED)Deleting linked_list_tools Library...$(DEF_COLOR)\n";
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
