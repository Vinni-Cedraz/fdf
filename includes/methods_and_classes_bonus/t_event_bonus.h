/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_event_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:11:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 22:09:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EVENT_BONUS_H
# define T_EVENT_BONUS_H

# include "../../libs/ft_printf_libft/libft/libft_bonus.h"
# include "fdf_prototypes_bonus.h"

typedef struct s_ev	t_event;

static void			hash_f(t_event *key) __attribute__((unused));

typedef struct s_ev
{
	int				key;
	t_func_ptr		f;
}					t_event;

typedef struct s_lookup
{
	t_node			*iso_transit_methods;
	t_node			*grid_methods;
	t_event			*events;
	void			(*set_hash)(t_event *events);
}					t_lookup;

static inline void	hash_f(t_event *events)
{
	int	hash;
	int	i;

	i = -1;
	while (++i <= 22)
	{
		hash = (events[i].key % 96) + 32;
		events[hash] = events[i];
	}
}

#endif
