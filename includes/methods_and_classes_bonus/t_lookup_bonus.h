/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lookup_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:51:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/16 11:31:46 by vcedraz-         ###   ########.fr       */
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
	return (key % 127);
}

static inline void	set_event_index_by_key(t_event *events)
{
	int	hash;
	int	i;

	i = -1;
	while (++i < 23)
	{
		hash = hash_function(events[i].key);
		events[hash] = events[i];
		events[i] = (t_event){0};
	}
}

#endif
