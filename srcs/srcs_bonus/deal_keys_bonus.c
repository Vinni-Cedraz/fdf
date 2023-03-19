/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/19 12:02:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	deal_keys_bonus(int key, t_data *d)
{
	static int	index;
	static int	previous_key;

	d->img->to_be_flushed = 1;
	if (previous_key != key)
	{
		index = d->lookup.hash_function(key);
		previous_key = key;
	}
	if (!d->lookup.events[index].t_event_method)
		return (0);
	d->lookup.events[index].t_event_method(d);
	return (1);
}
