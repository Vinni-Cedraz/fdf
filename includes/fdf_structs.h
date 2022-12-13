/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/13 12:59:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "printf_libft_structs.h"

typedef struct s_create_map
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	t_split	*split;
}			t_create_map;

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
