/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/31 17:27:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int	is_out_of_bounds(int key);

int	deal_keys_bonus(int key, t_data *d)
{
	if (is_out_of_bounds(key))
	{
		if (key == XK_ESCAPE)
			close_win_bonus(d);
		else
			return (0);
	}
	if (d->lookup.events[key])
		d->lookup.events[key](d);
	return (0);
}

static int	is_out_of_bounds(int key)
{
	if (key < 32 || key > 122)
		return (1);
	return (0);
}
