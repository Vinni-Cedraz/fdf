# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:57:13 by vcedraz-          #+#    #+#              #
#    Updated: 2023/02/05 18:18:05 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

SHELL := /bin/bash
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
AR = ar rcs
INCLUDES = -Iincludes/
OBJS_1_PATH = ./objs/
OBJS_LIB_PATH = ./libft/objs/
LIBFT_PATH = ./libft/
DEF_COLOR = \033[0;39m
GRAY = \033[0;37m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS_1 = ft_printf \
		     parser \
			 writers \
		  num_writers \
          call_writers \
  	   call_num_writers \

SRCS_LIB = ft_putchar \
             ft_calloc \
              ft_strlen \
               ft_memset \
             ft_itoa_base \
		   		   ft_itoa \
			     ft_ishexup \
				  ft_strlcat \
				    ft_strdup \
					   ft_swap \

SRCS_1_PATH = ./srcs/
SRCS_LIB_PATH = ./libft/
OBJS_1 = $(patsubst %, $(OBJS_1_PATH)%.o, $(SRCS_1))
OBJS_LIB = $(patsubst %, $(OBJS_LIB_PATH)%.o, $(SRCS_LIB))
OBJS_1_MOD = $(shell find $(OBJS_1_PATH)*.o -newer $(NAME))
OBJS_LIB_MOD = $(shell find $(OBJS_LIB_PATH)*.o -newer $(NAME))

## RULES ##
all: $(NAME)

libft_srcs_to_printf:
	@if [ ! -d $(OBJS_LIB_PATH) ]; then \
		make -C $(LIBFT_PATH) srcs_to_printf --no-print-directory; \
	fi	
		
$(NAME): $(OBJS_1) $(OBJS_LIB)
	@make libft_srcs_to_printf --no-print-directory
	@for file in $(OBJS_1_MOD); do \
		printf "\n$(YELLOW)a printf object has been modified...$(DEF_COLOR)\n"; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                              \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(OBJS_LIB_MOD); do \
		printf "\n$(YELLOW)an object from libft has been modified...$(DEF_COLOR)\n"; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                               \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS_1); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                                \r"; \
		ar -rsc $(NAME) $(OBJS_1_PATH)$$file.o; \
	fi; \
	done
	@if [ -d $(OBJS_LIB_PATH) ]; then \
		printf "\n$(YELLOW)Linking Objects to printflibft.a$(DEF_COLOR)\n"; \
		for file in $(SRCS_LIB); do \
			if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
			printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                          \r"; \
			ar -rsc $(NAME) $(OBJS_LIB_PATH)$$file.o; \
		fi; \
		done \
	fi
	@printf "$(CYAN)FT_PRINTF OK$(DEF_COLOR)                                                                                       \n";


$(OBJS_1_PATH)%.o: $(SRCS_1_PATH)%.c
	@mkdir -p $(OBJS_1_PATH)
	@make SRCS_1_LOOP --no-print-directory

$(OBJS_LIB_PATH)%.o: $(SRCS_LIB_PATH)%.c
	@if [ -d $(OBJS_LIB_PATH) ]; then \
		make SRCS_LIB_LOOP --no-print-directory; \
	fi

SRCS_1_LOOP:
	@printf "\n$(YELLOW)Compiling Printf Primary Functions...$(DEF_COLOR)\n";
	@for file in $(SRCS_1); do \
	if [ $(SRCS_1_PATH)$$file.c -nt $(OBJS_1_PATH)$$file.o ]; then \
		printf "\n$(GREEN)[ft_printf] $(CYAN)Compiling $(WHITE)$$file.c $(DEF_COLOR)\n"; \
		printf "$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS_1_PATH)$$file.c -o $(OBJS_1_PATH)$$file.o\n"; \
		$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS_1_PATH)$$file.c -o $(OBJS_1_PATH)$$file.o; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done

SRCS_LIB_LOOP:
	@printf "\n$(YELLOW)Compiling Libft Functions...$(DEF_COLOR)\n";
	@for file in $(SRCS_LIB); do \
	if [ $(SRCS_LIB_PATH)$$file.c -nt $(OBJS_LIB_PATH)$$file.o ]; then \
		printf "\n$(GREEN)[ft_printf] $(CYAN)Compiling $(WHITE)$$file.c $(DEF_COLOR)\n"; \
		printf "$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS_LIB_PATH)$$file.c -o $(OBJS_LIB_PATH)$$file.o\n"; \
		$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS_LIB_PATH)$$file.c -o $(OBJS_LIB_PATH)$$file.o; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	

clean:
	@if [ -d $(OBJS_1_PATH) ]; then \
		printf "$(GRAY)rm -rf $(OBJS_1_PATH)$(DEF_COLOR)"; \
		printf "\n$(RED)Primary Objects Deleted.$(DEF_COLOR)\n"; \
		rm -rf $(OBJS_1_PATH); \
	fi
	@rm -rf ./objs/
	@if [ -d $(OBJS_LIB_PATH) ]; then \
		printf "$(GRAY)rm -rf $(OBJS_LIB_PATH)$(DEF_COLOR)"; \
		printf "\n$(RED)Objects From Libft Deleted.$(DEF_COLOR)\n"; \
		rm -rf $(OBJS_LIB_PATH); \
	fi

fclean: clean
	@make fclean_all -C $(LIBFT_PATH) --no-print-directory
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "$(GRAY)rm -f $(NAME)$(DEF_COLOR)\n"; \
		printf "$(RED)$(NAME) $(GRAY)Deleted, Au Revoir.$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

re: fclean all

.PHONY: all clean fclean re
