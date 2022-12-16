/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:12:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 18:34:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	define_square(t_square *square, t_point p1, t_point p2)
{
	square->width_start = p1.x;
	square->height_start = p1.y;
	square->total_width = p2.x;
	square->total_height = p2.y;
}
