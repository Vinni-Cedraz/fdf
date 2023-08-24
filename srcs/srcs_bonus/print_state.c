/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:26:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/24 14:27:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	print_state(void)
{
	if (get_data()->state == parallel)
		printf("parallel\n");
	else if (get_data()->state == diagonal)
		printf("diagonal");
	else if (get_data()->state == isometric)
		printf("isometric\n");
	else if (get_data()->state == randomly_rotated)
		printf("randomly rotated\n");
	else if (get_data()->state == spherical)
		printf("spherical\n");
}
