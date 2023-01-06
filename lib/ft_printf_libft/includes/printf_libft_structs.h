/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:19:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/05 23:58:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_STRUCTS_H
# define PRINTF_LIBFT_STRUCTS_H

# include "printf_libft_defines.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uc;

typedef struct s_module
{
	char				*buf;
	int					l_bgn;
	int					l_end;
	int					l_sz;
	int					read;
}						t_module;

static inline void	destroy_module(t_module *mod)
{
	if (mod->buf)
		free(mod->buf);
	mod->buf = 0;
}

static	inline int	create_module(t_module *mod, int fd)
{
	mod->l_bgn = 0;
	mod->buf = malloc(BUFFER_SIZE);
	if (!mod->buf)
		return (1);
	mod->read = read(fd, mod->buf, BUFFER_SIZE);
	if (mod->read < 1)
		destroy_module(mod);
	if (mod->read < 0)
		return (1);
	while (mod->l_bgn < mod->read && mod->buf[mod->l_bgn] != '\n')
		mod->l_bgn++;
	if (mod->l_bgn < mod->read)
		mod->l_sz = mod->l_bgn + 1;
	else
		mod->l_sz = mod->l_bgn;
	mod->l_bgn++;
	mod->l_end = mod->l_bgn;
	return (0);
}

// typedef struct s_gnl
// {
// 	int					fd;
// 	t_module			mod_list[1024];
// 	t_module			mod;
// 	t_module			old;
// 	t_module			*neo;
// 	char				*line;
// 	char				*append;
// 	int					readed;
// 	int					cp_n_bts;
// 	int					sz;
// 	int					ln_sz;
// }						t_gnl;
//
typedef struct s_nodes
{
	void				*content;
	struct s_nodes		*next;
}						t_node;

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
