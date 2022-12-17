/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:19:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/17 14:40:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_STRUCTS_H
# define PRINTF_LIBFT_STRUCTS_H

# include <stdarg.h>
# include <stdlib.h>

typedef unsigned char	t_uc;

typedef struct s_point
{
	double					x;
	double					y;
	double					z;
	double					color;
}						t_point;

typedef struct s_map
{
	int					width;
	int					height;
	int					max_z;
	int					min_z;
	t_point				**arr;
}						t_map;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					width;
	int					height;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_plit
{
	char				*end;
	char				*start;
	char				**str_arr;
	size_t				i;
	size_t				words;

}						t_split;

typedef struct s_create_map
{
	int					x;
	int					y;
	int					fd;
	char				*line;
	t_split				*split;
}						t_create_map;

typedef struct s_data
{
	void				*win_ptr;
	void				*mlx_ptr;
	int					hook;
	int					scale_x;
	int					scale_y;
	float				move_x;
	float				move_y;
	t_img				*img;
	t_map				*map;
	t_create_map		tool;
}						t_data;

// this struct is just a box of tools, t_ools, got it? xD
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
	size_t				max;
	char				*lnbrk;
	char				*read;
	char				*wth_all;
	char				*bfr_brk;
	char				*aftbrk;
	int					aftbrk_len;
	int					bfrbrk_len;
	va_list				list;
}						t_ools;

#endif
