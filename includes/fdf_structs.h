/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/08 14:47:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct s_point
{
	int		x;
	int		y;
	int		color;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		hook;
}			t_data;

typedef struct s_quare
{
	int		height_start;
	int		width_start;
	int		total_height;
	int		total_width;
}			t_square;

typedef struct s_line
{
	float	x;
	float	y;
	float	x_inc;
	float	y_inc;
	int		dx;
	int		dy;
	int		steps;
	int		color;
}			t_line;

#endif
