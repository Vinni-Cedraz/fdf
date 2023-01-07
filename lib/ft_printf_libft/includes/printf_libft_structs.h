/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:19:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 13:48:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_STRUCTS_H
# define PRINTF_LIBFT_STRUCTS_H

# include "printf_libft_defines.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uc;

typedef struct s_mod
{
	short				read_failed;
	char				*buf;
	int					l_bgn;
	int					l_end;
	int					l_sz;
	int					read;
}						t_mod;

static inline void		destroy_module(t_mod *mod) __attribute__((unused));

static inline void	destroy_module(t_mod *mod)
{
	if (mod->buf)
		free(mod->buf);
	mod->buf = 0;
}

typedef struct s_plit
{
	char				*end;
	char				*start;
	char				**str_arr;
	size_t				i;
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

#endif
