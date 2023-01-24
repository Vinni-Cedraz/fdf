/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:40:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 21:28:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_TOOLS_H
# define LINKED_LIST_TOOLS_H

#include "fdf_t_point_bonus.h"

typedef unsigned int		t_ui;

typedef struct s_nd
{
	t_point					point;
	struct s_nd				*next;
}							t_node_with_a_point;

typedef t_node_with_a_point	t_n;

// ads a node_with_a_point and initializes the point to all zeros
t_n							*ft_lstpoint_new(void);

// ft_lstpoint_back	adds a t_node_with_a_point to the end of a list
void						ft_lstpoint_back(t_n **lst, t_n *tail);

// ft_lstpoint_front adds a t_node_with_a_point to the beginning of a list
void						ft_lstpoint_front(t_n **lst, t_n *tail);

// ft_lstpoint_print prints the content of a list of t_node_with_a_point
void						ft_lstpoint_print(t_n **lst);

// returns a pointer to the t_node_with_a_point at the i position in the list
t_n							*ft_lstpoint_getby_index(t_n *lst, t_ui i);

// frees the nodes of a list but not the list itself:
void						ft_lstpoint_free(t_n **list);

// just ft_lstsize but for t_node_with_a_point
int							ft_lstpoint_size(t_n *lst);

// to transform a linked list of ode_with_a_points into a 2d array of t_points
t_point						**ft_lstpoint_toarr(t_n *node, t_ui width);

// duplicates a linked list of 't_node_with_a_point' s
t_n							*ft_lstpoint_dup(t_n *lst);

#endif
