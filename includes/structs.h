/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/03 13:37:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		xdif;
	int		ydif;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
}			t_line;

#endif
