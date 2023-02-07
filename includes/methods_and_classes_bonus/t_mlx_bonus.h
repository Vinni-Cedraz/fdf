/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:54:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 11:56:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_BONUS_H
# define T_MLX_BONUS_H

# include "printf_libft_includes.h"
# include <stdio.h>

typedef struct s_mlx
{
	void	*win_ptr;
	void	*ptr;
	int		hook;
}			t_mlx;

typedef struct s_assign_coordinates
{
	FILE	*fp;
	char	*argv;
	char	*first_line;
	t_split	*pts_in_this_row;
}			t_assign_coordinates;

typedef struct s_img
{
	int		width;
	int		height;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

#endif
