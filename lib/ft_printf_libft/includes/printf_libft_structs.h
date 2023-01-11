/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:19:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:56:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_STRUCTS_H
# define PRINTF_LIBFT_STRUCTS_H

# include "printf_libft_defines.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_plit
{
	char	*end;
	char	*start;
	char	**str_arr;
	size_t	words;

}			t_split;

typedef struct s_tools
{
	size_t	abs;
	size_t	counter;
	size_t	len;
	size_t	size;
	size_t	half;
	size_t	baselen;
	size_t	sign;
	va_list	list;
}			t_ools;

typedef enum s_enum
{
	TAB = 9,
	NEWLINE = 10,
	VERTICAL_TAB = 11,
	FORMFEED = 12,
	CARRIAGE_RETURN = 13,
	SPACE = ' ',
}			t_whitespace;

typedef struct s_counters
{
	size_t	chars;
	size_t	counter;
	size_t	prntd;
	size_t	chckd;
	size_t	from_start;
	size_t	from_end;
}			t_counters;

typedef struct s_tring
{
	char	*str;
	char	*res;
	char	*tmp;
	char	*to_ascii;
}			t_string;

typedef struct s_gnl
{
	char	*read;
	char	*line;
	char	*bfr_brk;
	char	*lnbrk;
	char	*aftbrk;
	char	*wth_all;
	size_t	bfrbrk_len;
	size_t	aftbrk_len;
	size_t	len;
}			t_gnl;

typedef struct s_read_one
{
	char	*buf;
	char	*read;
	char	*res;
	size_t	len;
	size_t	i;
	size_t	max;
}			t_read_one;

#endif
