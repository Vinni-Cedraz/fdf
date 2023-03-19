/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lookup_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:51:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/19 12:12:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LOOKUP_BONUS_H
# define T_LOOKUP_BONUS_H

# include "../../libs/ft_printf_libft/libft/libft_bonus.h"
# include "fdf_prototypes_bonus.h"

typedef struct s_ev	t_event;

static void			set_event_index_by_key(t_event *ev) __attribute__((unused));
static int			hash_function(int key) __attribute__((unused));

typedef struct s_ev
{
	int				key;
	t_func_ptr		t_event_method;
}					t_event;

typedef struct s_lookup
{
	t_node			*transition_methods;
	t_node			*grid_methods;
	t_event			*events;
	void			(*set_event_index_by_key)(t_event *);
	int				(*hash_function)(int);
}					t_lookup;

static inline int	hash_function(int key)
{
	int	x;

	x = key;
	x = (x ^ (x >> 12));
	x = ((x << 7) | (x << 3) | (x << 2)) ^ ((x << 11) | 0b01001100000010111010110010110011);
	x = (x ^ (x >> 16));
	x = ((x << 13) | (x << 3) | (x << 1)) ^ ((x << 11) | 0b10000101111010111100101001101011);
	x = x ^ (x >> 13);
	return ((x & 0x7f) | 21);
}

static inline void	set_event_index_by_key(t_event *events)
{
	int	hash;
	int	i;

	i = -1;
	while (++i <= 0b10110)
	{
		hash = hash_function((*(events + i)).key);
		*(events + hash) = *(events + i);
	}
}

#endif
