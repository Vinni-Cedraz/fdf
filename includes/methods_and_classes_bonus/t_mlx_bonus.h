/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:54:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 16:28:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_BONUS_H
# define T_MLX_BONUS_H

# include "printf_libft_includes.h"
# include <stdio.h>

typedef struct s_mlx
{
	void	*win_ptr;
	void	*display_ptr;
	int		hook;
}			t_mlx;

typedef struct s_img
{
	int		width;
	int		height;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		to_be_flushed;
}			t_img;

#endif
