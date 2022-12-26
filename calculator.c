/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:28:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 16:15:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	double	a;
	double	b;
	double	c;
	double	theta;
	double	aux;

	(void)argc;
	b = atof(argv[1]);
	c = atof(argv[2]);
	theta = atof(argv[3]) * M_PI / 180;
	aux = pow(b, 2) + pow(c, 2) - 2 * b * c * cos(theta);
	a = sqrt(aux);
	printf("a = %f", a);
}
