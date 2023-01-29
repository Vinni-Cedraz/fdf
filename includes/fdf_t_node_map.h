/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_node_map.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:49:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/28 19:30:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_NODE_MAP_H
# define FDF_T_NODE_MAP_H

# include "fdf_t_point.h"

typedef struct s_nd
{
	t_point							point;
	struct s_nd						*next;
}									t_node_with_a_point;

static t_node_with_a_point			*create_n_map(void) __attribute__((unused));

typedef struct s_nm
{
	t_node_with_a_point				*head;
	t_node_with_a_point				*(*create_node)(void);
}									t_node_map;

typedef struct s_nd					t_n;

static inline t_node_with_a_point	*create_n_map(void)
{
	t_node_with_a_point	*pts;

	pts = malloc(sizeof(t_node_with_a_point));
	pts->point = (t_point){0, 0, 0, 0, NULL, NULL};
	pts->next = NULL;
	return (pts);
}

#endif
