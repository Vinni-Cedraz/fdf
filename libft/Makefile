# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:11:55 by vcedraz-          #+#    #+#              #
#    Updated: 2022/12/04 16:52:06 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

SHELL := /bin/bash

NAME = libft.a

NAME_BONUS = libft_bonus.a

NAME_PRNTF = srcs_to_printf.a

NAME_FDF = srcs_to_fdf.a

CFLAGS = -Wall -Werror -Wextra -g

AR = ar -rs

RM = rm -f

OBJS_PATH = ./objs/

OBJSB_PATH = ./objs_bonus/

PRNTF_OBJS_PATH = ./objs_printf/

FDF_OBJS_PATH = ./objs_fdf/

DEF_COLOR = \033[0;39m
GRAY = \033[0;37m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS = ft_atoi \
ft_free_arr \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_memchr \
ft_memcmp \
ft_putchar \
ft_putchar_fd \
ft_strlen \
ft_strncmp \
ft_word_counter \
ft_abs \
ft_memcpy \
ft_memset \
ft_numlen \
ft_putstr \
ft_putstr_fd \
ft_striteri \
ft_strrchr \
ft_strrev \
ft_tolower \
ft_toupper \
ft_bzero \
ft_memmove \
ft_putendl_fd \
ft_rev_int_tab \
ft_sort_int_tab \
ft_strchr \
ft_strmapi \
ft_strnstr \
ft_calloc \
ft_memorylen \
ft_strdup \
ft_strlcat \
ft_itoa_base \
ft_strjoin \
ft_strtrim \
ft_swap \
ft_putnbr_fd \
ft_substr \
ft_split \
ft_strlcpy \
ft_itoa \
ft_hexdump \
ft_gnl \

BSRCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstdelone \
ft_lstlast \
ft_lstnew \
ft_lstsize \
	
PRNTF_SRCS = ft_putchar \
ft_strlen \
ft_memset \
ft_calloc \
ft_itoa_base \

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
			 ft_gnl \

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
OBJSB = $(patsubst %, $(OBJSB_PATH)%.o, $(BSRCS))
OBJS_PRNTF = $(patsubst %, $(PRNTF_OBJS_PATH)%.o, $(PRNTF_SRCS))
OBJS_FDF = $(patsubst %, $(FDF_OBJS_PATH)%.o, $(FDF_SRCS))
MOD_OBJ = $(shell find . -path "./objs/*.o" -type f -newer $(NAME))
MOD_OBJB = $(shell find . -path "./objs_bonus/*.o" -type f -newer $(NAME_BONUS))
MOD_OBJ_PRNTF = $(shell find . -path "./objs_printf/*.o" -type f -newer $(NAME_PRNTF))
MOD_OBJ_FDF = $(shell find . -path "./objs_fdf/*.o" -type f -newer $(NAME_FDF))
MOD_MK = $(shell find . -name "Makefile" -type f -newer $(NAME) || $(NAME_FDF) || $(NAME_PRNTF) || $(NAME_BONUS))
MOD_H = $(shell find . -name "*.h" -type f -newer $(NAME) || $(NAME_FDF) || $(NAME_PRNTF) || $(NAME_BONUS))

all : $(NAME) 

bonus : $(NAME_BONUS)

srcs_to_printf : $(NAME_PRNTF)

srcs_to_fdf : $(NAME_FDF)

header_makefile:
	@if [ -n "$(MOD_MK)" ] || [ -n "$(MOD_H)" ]; then \
		printf "$(WHITE)EITHER A$(CYAN) HEADER FILE $(WHITE)OR A$(CYAN) MAKEFILE $(WHITE)HAVE BEEN MODIFIED...\nPROJECT HAS TO BE RECOMPILED\n$(DEF_COLOR)"; \
		sleep 3; \
		printf "$(WHITE)Now you should run $(CYAN)\"make re\" followed by the rule of your project $(WHITE)to remake everything!\n$(DEF_COLOR)"; \
		sleep 2; \
	fi

$(NAME) : $(OBJS) header_makefile
	@for file in $(MOD_OBJ); do \
		printf "\n$(CYAN)linking $(WHITE)$$file$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME) $$file\n"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
	if [ ! -f $(NAME) ]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME) $$file.o\n"; \
	fi; \
	if [[ -z "$$(nm $(NAME) | grep $${file})" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME) $$file.o\n"; \
	fi; \
	done

$(NAME_PRNTF) : $(OBJS_PRNTF) header_makefile
	@for file in $(MOD_OBJ_PRNTF); do \
		printf "\n$(CYAN)linking $(WHITE)$$file$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_PRNTF) $$file\n"; \
		ar -rsc $(NAME_PRNTF) $$file; \
	done
	@for file in $(PRNTF_SRCS); do \
	if [ ! -f $(NAME_PRNTF) ]; then \
		ar -rsc $(NAME_PRNTF) $(PRNTF_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_PRNTF) $$file.o\n"; \
	fi; \
	if [[ -z "$$(nm $(NAME_PRNTF) | grep $${file})" ]]; then \
		ar -rsc $(NAME_PRNTF) $(PRNTF_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_PRNTF) $$file.o\n"; \
	fi; \
	done

$(NAME_FDF) : $(OBJS_FDF) header_makefile
	@for file in $(MOD_OBJ_FDF); do \
		printf "\n$(CYAN)linking $(WHITE)$$file$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_FDF) $$file\n"; \
		ar -rsc $(NAME_FDF) $$file; \
	done
	@for file in $(FDF_SRCS); do \
	if [ ! -f $(NAME_FDF) ]; then \
		ar -rsc $(NAME_FDF) $(FDF_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_FDF) $$file.o\n"; \
	fi; \
	if [[ -z "$$(nm $(NAME_FDF) | grep $${file})" ]]; then \
		ar -rsc $(NAME_FDF) $(FDF_OBJS_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_FDF) $$file.o\n"; \
	fi; \
	done

$(NAME_BONUS) : $(NAME) $(OBJSB) header_makefile
	@cp $(NAME) $(NAME_BONUS)
	@for file in $(MOD_OBJB); do \
		printf "\n$(CYAN)linking $(WHITE)$$file$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_BONUS) $$file\n"; \
		ar -rsc $(NAME_BONUS) $$file; \
	done
	@for file in $(BSRCS); do \
	if [ ! -f $(NAME_BONUS) ]; then \
		ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_BONUS) $$file.o\n"; \
	fi; \
	if [[ -z "$$(nm $(NAME_BONUS) | grep $${file})" ]]; then \
		ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o; \
		printf "\n$(CYAN)linking $(WHITE)$$file.o$(DEF_COLOR)\n"; \
		printf "ar -rsc $(NAME_BONUS) $$file.o\n"; \
	fi; \
	done

$(OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling All libft Sources...$(DEF_COLOR)\n"
	@make LIBFT_LOOP --no-print-directory

$(OBJSB_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Bonus libft Sources...$(DEF_COLOR)\n"
	@make BONUS_LIBFT_LOOP --no-print-directory

$(PRNTF_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling libft Sources... $(DEF_COLOR)\n"
	@make PRNTF_LOOP --no-print-directory

$(FDF_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling libft Sources... $(DEF_COLOR)\n"
	@make FDF_LOOP --no-print-directory

FDF_LOOP :
	@mkdir -p $(FDF_OBJS_PATH)
	@for file in $(FDF_SRCS); do \
	if [ $$file.c -nt $(FDF_OBJS_PATH)$$file.o ]; then \
		printf "$(CYAN)Compiling $(WHITE)$$file.c...$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJS_PATH)$$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file.c $(GREEN)OK$(DEF_COLOR)\n\n"; \
	fi; \
	done

PRNTF_LOOP :
	@mkdir -p $(PRNTF_OBJS_PATH)
	@for file in $(PRNTF_SRCS); do \
		if [ $$file.c -nt $(PRNTF_OBJS_PATH)$$file.o ]; then \
		printf "$(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(PRNTF_OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(PRNTF_OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(PRNTF_OBJS_PATH)$(DEF_COLOR)\n" \

LIBFT_LOOP :
	@mkdir -p $(OBJS_PATH)
	@for file in $(SRCS); do \
		if [ $$file.c -nt $(OBJS_PATH)$$file.o ]; then \
		printf "$(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(OBJS_PATH)$(DEF_COLOR)\n" \

BONUS_LIBFT_LOOP :
	@mkdir -p $(OBJSB_PATH)
	@for file in $(BSRCS); do \
		if [ $$file.c -nt $(OBJSB_PATH)$$file.o ]; then \
		printf "$(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(OBJSB_PATH)$(DEF_COLOR)\n" \

clean :
	@rm -rf $(OBJS_PATH)
	@rm -rf $(OBJSB_PATH)
	@rm -rf $(PRNTF_OBJS_PATH)
	@rm -rf $(FDF_OBJS_PATH)
	@rm -f a.out

clean_printf:
	@rm -rf $(PRNTF_OBJS_PATH)
	@rm -f a.out
	@printf "$(RED)Printf Objects From Libft Removed$(DEF_COLOR)\n"

clean_fdf:
	@rm -rf $(FDF_OBJS_PATH)
	@rm -f a.out
	@printf "$(RED)FDF Objects From Libft Removed$(DEF_COLOR)\n"

clean_bonus :
	@rm -rf $(OBJSB_PATH)
	@printf "$(RED)Bonus Objects From Libft Removed$(DEF_COLOR)\n"

fclean : clean
	$(RM) $(NAME)

fclean_printf : clean_printf
	$(RM) $(NAME_PRNTF)

fclean_fdf : clean_fdf
	$(RM) $(NAME_FDF)

fclean_bonus : clean_bonus
	$(RM) $(NAME_BONUS)

re : fclean all

re_printf : fclean_printf srcs_to_printf

re_fdf : fclean_fdf srcs_to_fdf

re_bonus : fclean_bonus srcs_to_bonus

phony : all clean fclean re bonus printf
