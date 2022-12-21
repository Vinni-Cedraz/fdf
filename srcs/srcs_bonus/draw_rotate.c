/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:07:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 04:09:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	rotate_x(double *y, double *z, double *alpha)
{
	double	aux;

	aux = *y;
	*y = aux * cos(*alpha) + *z * sin(*alpha);
	*z = -aux * sin(*alpha) + *z * cos(*alpha);
}

void	rotate_y(double *x, double *z, double *beta)
{
	double	aux;

	aux = *x;
	*x = aux * cos(*beta) + *z * sin(*beta);
	*z = -aux * sin(*beta) + *z * cos(*beta);
}

void	rotate_z(double *x, double *y, double *gamma)
{
	double	aux_x;
	double	aux_y;

	aux_x = *x;
	aux_y = *y;
	*x = aux_x * cos(*gamma) - aux_y * sin(*gamma);
	*y = aux_x * sin(*gamma) + aux_y * cos(*gamma);
}

void	isometric(double *x, double *y, double z)
{
	double	aux_x;
	double	aux_y;

	aux_x = (*x - *y) * cos(0.523599);
	aux_y = -z + (*x + *y) * sin(0.523599);
	*x = aux_x;
	*y = aux_y;
}
