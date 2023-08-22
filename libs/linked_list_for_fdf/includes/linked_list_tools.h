/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:21:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/21 17:41:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_TOOLS_H
# define LINKED_LIST_TOOLS_H

# include "../includes/methods_and_classes_bonus/t_point_bonus.h"

typedef unsigned int	t_ui;

typedef struct s_nd		t_n;

typedef struct s_xy_range
{
	double				max_x;
	double				min_x;
	double				max_y;
	double				min_y;
}						t_xy_range;

typedef t_xy_range		t_xy;

typedef struct s_nd
{
	t_point				point;
	t_n					*next;
}						t_n;

typedef					void(t_point_apply_fptr)(t_point *);
typedef					t_xy_range(t_point_calc_fptr)(t_point *, t_xy_range);

// ads a node_with_a_point and initializes the point to all zeros
t_n						*ft_lstpoint_new(void);

// ft_lstpoint_back	adds a t_node_with_a_point to the end of a list
void					ft_lstpoint_back(t_n **lst, t_n *tail);

// ft_lstpoint_front adds a t_node_with_a_point to the beginning of a list
void					ft_lstpoint_front(t_n **lst, t_n *tail);

// ft_lstpoint_print prints the content of a list of t_node_with_a_point
void					ft_lstpoint_print(t_n **lst);

// returns a pointer to the t_node_with_a_point at the i position in the list
t_n						*ft_lstpoint_getby_index(t_n *lst, t_ui i);

// frees the nodes of a list but not the list itself:
void					ft_lstpoint_free(t_n **list);

// just ft_lstsize but for t_node_with_a_point
int						ft_lstpoint_size(t_n *lst);

// to transform a linked list of ode_with_a_points into a 2d array of t_points
void					ft_lstpoint_toarr(t_n *n, t_ui width, t_point **arr);

// duplicates a linked list of 't_node_with_a_point' s
t_n						*ft_lstpoint_dup(t_n *lst);

// makes a linked list of 't_node_with_a_point' circular
void					ft_lstpoint_make_it_circular(t_n **head);

// iterates circular linked list of t_node_with_a_point doing t_point_apply_fptr
void					ft_lstpoint_iter(t_n *head, t_point_apply_fptr *f);

// iterates circular linked list of t_node_with_a_point while calculating stuff
t_xy_range				ft_lstpoint_iter_and_get(t_n *h, t_point_calc_fptr *f);

#endif
