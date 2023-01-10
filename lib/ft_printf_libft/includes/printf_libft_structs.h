/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:19:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 13:27:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_STRUCTS_H
# define PRINTF_LIBFT_STRUCTS_H

# include "printf_libft_defines.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uc;

typedef struct s_plit
{
	char				*end;
	char				*start;
	char				**str_arr;
	size_t				words;

}						t_split;

typedef struct s_tools
{
	size_t				i;
	size_t				chars;
	size_t				counter;
	size_t				prntd;
	size_t				chckd;
	char				*str;
	char				*res;
	char				*tmp;
	char				*to_ascii;
	size_t				len;
	size_t				size;
	size_t				half;
	size_t				baselen;
	size_t				sign;
	size_t				from_start;
	size_t				from_end;
	size_t				result;
	size_t				abs;
	va_list				list;
}						t_ools;

typedef struct s_gnl
{
	size_t				bfrbrk_len;
	size_t				aftbrk_len;
	size_t				len;
	char				*read;
	char				*line;
	char				*bfr_brk;
	char				*lnbrk;
	char				*aftbrk;
	char				*wth_all;
}						t_gnl;

typedef struct s_read_one
{
	char				*buf;
	char				*read;
	char				*res;
	size_t				len;
	size_t				i;
	size_t				max;
}						t_read_one;

#endif
