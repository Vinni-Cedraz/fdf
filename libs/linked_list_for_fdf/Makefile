# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:33:51 by vcedraz-          #+#    #+#              #
#    Updated: 2023/02/12 21:41:55 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ VARIABLES ################

SHELL := /bin/bash					
NAME = linked_list_tools.a
INC_LIBFT = ../ft_printf_libft/libft/
INC_PRINTF = ../ft_printf_libft/includes/
INC_FDF = ../../includes/
INC_METHODS = ../../includes/methods_and_classes_bonuss/
INC = includes/
CFLAGS = -Wall -Wextra -Werror -g \
		 -I$(INC_LIBFT) \
		 -I$(INC_PRINTF) \
		 -I$(INC_FDF) \
		 -I$(INC) \
		 -I$(INC_METHODS)
SRCS_PATH = srcs/
OBJS_PATH = objs/
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

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))
################# COMPILING AND LINKING RULES #################

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Linking linked_list_tools Objects to Library...$(DEF_COLOR)\n";
	@for file in $(OBJS); do \
		ar -rsc $(NAME) $$file; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                          \r"; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                           \r"; \
		fi; \
	done
	@printf "$(WHITE)Created Library $(RED)linked_list_tools.a $(DEF_COLOR)                                                                                     \n";

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP:
	@for file in $(SRCS); do \
		if [ $(SRCS_PATH)$$file.c -nt $(OBJS_PATH)$$file.o ]; then \
			printf "\n\n$(GREEN)[linked_list_tools] $(CYAN)Compiling $(WHITE)$$file\n"; \
			printf "$(GRAY)cc -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o\n$(DEF_COLOR)"; \
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
