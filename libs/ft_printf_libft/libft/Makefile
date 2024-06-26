# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:11:55 by vcedraz-          #+#    #+#              #
#    Updated: 2023/02/24 16:18:52 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## SET-UP VARIABLES ##
SHELL := /bin/bash
NAME = libft.a
NAME_BONUS = libft_bonus.a
NAME_PRNTF = ../libftprintf.a
NAME_FDF = srcs_to_fdf.a
NAME_FDF_BONUS = srcs_to_fdf_bonus.a
CFLAGS = -Wall -Werror -Wextra -O3
AR = ar -rs
RM = rm -f
OBJS_PATH = ./objs/
OBJSB_PATH = ./objs_bonus/
PRNTF_OBJS_PATH = ./objs_printf/
FDF_OBJS_PATH = ./objs_fdf/
FDF_OBJSB_PATH = ./objs_fdf_bonus/
DEF_COLOR = \033[0;39m
GRAY = \033[0;37m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

## SRCS VARIABLES ##
SRCS = ft_abs \
ft_atoi \
ft_free_t_split \
ft_free_arr \
ft_free_arr_size \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_ishexup \
ft_ishexlow \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memorylen \
ft_memset \
ft_numlen \
ft_putchar \
ft_putchar_fd \
ft_strlen \
ft_atoi_base \
ft_strncmp \
ft_word_counter \
ft_calloc \
ft_hexdump \
ft_memmove \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_rev_int_tab \
ft_striteri \
ft_strrchr \
ft_strrev \
ft_swap \
ft_tolower \
ft_toupper \
ft_bzero \
ft_isalnum \
ft_itoa_base \
ft_putendl_fd \
ft_sort_int_tab \
ft_strchr \
ft_strdup \
ft_strlcat \
ft_strlcpy \
ft_strmapi \
ft_strnstr \
ft_strjoin \
ft_strtrim \
ft_substr \
ft_gnl \
ft_itoa \
ft_split \

BSRCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstfree \
ft_lstlast \
ft_lstnew \
ft_lstsize \
ft_lstprint \
ft_lstadd_here \
ft_lstdel_here \
ft_lstgetby_index \
ft_lstgetby_content \
ft_lst_make_it_circular \
ft_lstcircular_free \
ft_lstpop \
ft_lstshift \
	

PRNTF_SRCS = ft_putchar \
               ft_calloc \
                ft_strlen \
                 ft_memset \
               ft_itoa_base \
		   		     ft_itoa \
			       ft_ishexup \
				    ft_strlcat \
				      ft_strdup \
					     ft_swap \


FDF_SRCS = ft_strnstr \
			   ft_swap \
		    ft_free_arr \
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
						    ft_putstr \
							  ft_bzero \

FDF_SRCS_BONUS =  ft_strnstr \
					  ft_swap \
			  ft_free_arr_size \
				ft_free_t_split \
					ft_atoi_base \
				  ft_word_counter \
						 ft_strlen \
				             ft_gnl \
						 ft_ishexlow \
						   ft_ishexup \
							 ft_calloc \
							    ft_atoi \
							   ft_memchr \
								 ft_split \
							    ft_strjoin \
								  ft_memcpy \
								   ft_strdup \
								   ft_strtrim \
								     ft_substr \
									  ft_putstr \
									   ft_strchr \
									    ft_lstnew \
								   	ft_lstadd_back \
								         ft_lstlast \
							 ft_lst_make_it_circular \
							 	  ft_lstcircular_free \
							                ft_lstfree \
											   ft_bzero \

## OBJS VARIABLES ##

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
OBJSB = $(patsubst %, $(OBJSB_PATH)%.o, $(BSRCS))
OBJS_PRNTF = $(patsubst %, $(PRNTF_OBJS_PATH)%.o, $(PRNTF_SRCS))
OBJS_FDF = $(patsubst %, $(FDF_OBJS_PATH)%.o, $(FDF_SRCS))
OBJSB_FDF = $(patsubst %, $(FDF_OBJSB_PATH)%.o, $(FDF_SRCS_BONUS))
MOD_OBJ = $(shell find . -path "./objs/*.o" -type f -newer $(NAME))
MOD_OBJB = $(shell find . -path "./objs_bonus/*.o" -type f -newer $(NAME_BONUS))
MOD_OBJ_PRNTF = $(shell find . -path "./objs_printf/*.o" -type f -newer $(NAME_PRNTF))
MOD_OBJ_FDF = $(shell find . -path "./objs_fdf/*.o" -type f -newer $(NAME_FDF))
MOD_OBJB_FDF = $(shell find . -path "./objs_fdf_bonus/*.o" -type f -newer $(NAME_FDF_BONUS))

## COMPILATION RULES ##

all : $(NAME) 

srcs_to_printf : $(NAME_PRNTF)

srcs_to_fdf_bonus: $(NAME_FDF_BONUS)

srcs_to_fdf : $(NAME_FDF)

bonus : $(NAME_BONUS)

all_all: all srcs_to_printf srcs_to_fdf bonus

$(NAME) : $(OBJS) 
	@printf "\n$(YELLOW)Linking Mandatory Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                                         \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                                        \r"; \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME)$(DEF_COLOR)                                                                              \n"; \

$(NAME_PRNTF) : $(OBJS_PRNTF) 
	@printf "\n$(YELLOW)Linking Printf Objects From Libft to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ_PRNTF); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_PRNTF)$(DEF_COLOR)                                                      \r"; \
		ar -rsc $(NAME_PRNTF) $$file; \
	done
	@for file in $(PRNTF_SRCS); do \
	if [[ -z "$$(nm $(NAME_PRNTF) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_PRNTF)$(DEF_COLOR)                                                       \r"; \
		ar -rsc $(NAME_PRNTF) $(PRNTF_OBJS_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)libftprintf.a$(DEF_COLOR)                                                                           \n"; \

$(NAME_FDF) : $(OBJS_FDF) 
	@printf "\n$(YELLOW)Linking fdf Objects From libft to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ_FDF); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_FDF)$(DEF_COLOR)                                                           \r"; \
		ar -rsc $(NAME_FDF) $$file; \
	done
	@for file in $(FDF_SRCS); do \
	if [[ -z "$$(nm $(NAME_FDF) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME_FDF)$(DEF_COLOR)                                                          \r"; \
		ar -rsc $(NAME_FDF) $(FDF_OBJS_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_PRNTF)$(DEF_COLOR)                                                                              \n"; \

$(NAME_FDF_BONUS) : $(OBJSB_FDF)
	@printf "\n$(YELLOW)Linking fdf Bonus Objects From libft to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJB_FDF); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_FDF_BONUS)$(DEF_COLOR)                                                        \r"; \
		ar -rsc $(NAME_FDF_BONUS) $$file; \
	done
	@for file in $(FDF_SRCS_BONUS); do \
	if [[ -z "$$(nm $(NAME_FDF_BONUS) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME_FDF_BONUS)$(DEF_COLOR)                                                      \r"; \
		ar -rsc $(NAME_FDF_BONUS) $(FDF_OBJSB_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_PRNTF)$(DEF_COLOR)                                                                                \n"; \

$(NAME_BONUS) : $(NAME) $(OBJSB) 
	@printf "\n$(YELLOW)Creating $(NAME_BONUS) Library With ALL Objects from libft...$(DEF_COLOR)\n";
	@if	[[ -z "$$(nm $(NAME_BONUS) | grep ft_lstnew.o:)" ]]; then \
		cp $(NAME) $(NAME_BONUS); \
	fi
	@for file in $(MOD_OBJB); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                             \r"; \
		ar -rsc $(NAME_BONUS) $$file; \
	done
	@for file in $(BSRCS); do \
	if [[ -z "$$(nm $(NAME_BONUS) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                              \r"; \
		printf "ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                                                \n"; \

$(OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling All libft Sources...$(DEF_COLOR)\n\n"
	@make LIBFT_LOOP --no-print-directory

$(OBJSB_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Bonus libft Sources...$(DEF_COLOR)\n\n"
	@make BONUS_LIBFT_LOOP --no-print-directory

$(PRNTF_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Libft Sources to Printf... $(DEF_COLOR)\n\n"
	@make PRNTF_LOOP --no-print-directory

$(FDF_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling libft Sources... $(DEF_COLOR)\n\n"
	@make FDF_LOOP --no-print-directory

$(FDF_OBJSB_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Bonus libft Sources... $(DEF_COLOR)\n\n"
	@make FDF_BONUS_LOOP --no-print-directory

FDF_LOOP :
	@mkdir -p $(FDF_OBJS_PATH)
	@for file in $(FDF_SRCS); do \
	if [ $$file.c -nt $(FDF_OBJS_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file.c...$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJS_PATH)$$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file.c $(GREEN)OK$(DEF_COLOR)\n\n"; \
	fi; \
	done

FDF_BONUS_LOOP :
	@mkdir -p $(FDF_OBJSB_PATH)
	@for file in $(FDF_SRCS_BONUS); do \
	if [ $$file.c -nt $(FDF_OBJSB_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file.c...$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJSB_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(FDF_OBJSB_PATH)$$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file.c $(GREEN)OK$(DEF_COLOR)\n\n"; \
	fi; \
	done

PRNTF_LOOP :
	@mkdir -p $(PRNTF_OBJS_PATH)
	@for file in $(PRNTF_SRCS); do \
		if [ $$file.c -nt $(PRNTF_OBJS_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
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
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
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
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(OBJSB_PATH)$(DEF_COLOR)\n" \

## CLEANING RULES ##
clean_all :
	@make clean --no-print-directory
	@make clean_bonus --no-print-directory
	@make clean_fdf --no-print-directory
	@make clean_printf --no-print-directory
	
clean:
	@if [ -d $(OBJS_PATH) ]; then \
		rm -rf $(OBJS_PATH); \
		printf "$(RED)Libft Objects Removed$(DEF_COLOR)\n"; \
	fi
	@if [ -d $(OBJSB_PATH) ]; then \
		rm -rf $(OBJSB_PATH); \
		printf "$(RED)Libft Bonus Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_libft:
	@if [ -d $(OBJS_PATH) ]; then \
		rm -rf $(OBJS_PATH); \
		printf "$(RED)Libft Objects Removed$(DEF_COLOR)\n"; \
	fi

clean_printf:
	@if [ -d $(PRNTF_OBJS_PATH) ]; then \
		rm -rf $(PRNTF_OBJS_PATH); \
		printf "$(RED)Printf Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_fdf:
	@if [ -d $(FDF_OBJS_PATH) ]; then \
		rm -rf $(FDF_OBJS_PATH); \
		printf "$(RED)FDF Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_fdf_bonus:
	@if [ -d $(FDF_OBJSB_PATH) ]; then \
		rm -rf $(FDF_OBJSB_PATH); \
		printf "$(RED)FDF Bonus Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_bonus :
	@if [ -d $(OBJSB_PATH) ]; then \
		rm -rf $(OBJSB_PATH); \
		printf "$(RED)Bonus Libft Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

fclean_all : fclean_printf fclean_fdf fclean_bonus fclean

fclean :
	@make clean --no-print-directory;
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "$(RED)$(NAME) Removed$(DEF_COLOR)\n"; \
	fi
	@make fclean_bonus --no-print-directory

fclean_libft :
	@make clean_libft --no-print-directory;
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "$(RED)$(NAME) Removed$(DEF_COLOR)\n"; \
	fi

fclean_printf :
	@make clean_printf --no-print-directory;
	@if [ -f $(NAME_PRNTF) ]; then \
		rm -f $(NAME_PRNTF); \
		printf "$(RED)$(NAME_PRNTF) Removed$(DEF_COLOR)\n"; \
	fi

fclean_fdf :
	@make clean_fdf --no-print-directory;
	@if [ -f $(NAME_FDF) ]; then \
		rm -f $(NAME_FDF); \
		printf "$(RED)$(NAME_FDF) Removed$(DEF_COLOR)\n"; \
	fi

fclean_fdf_bonus :
	@make clean_fdf_bonus --no-print-directory;
	@if [ -f $(NAME_FDF_BONUS) ]; then \
		rm -f $(NAME_FDF_BONUS); \
		printf "$(RED)$(NAME_FDF_BONUS) Removed$(DEF_COLOR)\n"; \
	fi

fclean_bonus :
	@make clean_bonus --no-print-directory;
	@if [ -f $(NAME_BONUS) ]; then \
		rm -f $(NAME_BONUS); \
		printf "$(RED)$(NAME_BONUS) Removed$(DEF_COLOR)\n"; \
	fi

re : fclean all

re_printf : fclean_printf srcs_to_printf

re_fdf : fclean_fdf srcs_to_fdf

re_bonus : fclean_bonus srcs_to_bonus

phony : all clean fclean re bonus printf
