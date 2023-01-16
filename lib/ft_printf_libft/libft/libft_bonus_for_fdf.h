/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus_for_fdf.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:07:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/16 15:33:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_FOR_FDF_H
# define LIBFT_BONUS_FOR_FDF_H

# include "../../../includes/t_point_bonus.h"
# include <stdlib.h>

typedef t_node_with_a_point	t_n;
typedef double				t_d;
typedef struct s_data		t_data;

// ads a node_with_a_point and initializes the point to all zeros
t_n							*ft_lstpoint_new(void);

// ft_lstpoint_back	adds a t_node_with_a_point to the end of a list
void						ft_lstpoint_back(t_n **lst, t_n *tail);

// ft_lstpoint_front adds a t_node_with_a_point to the beginning of a list
void						ft_lstpoint_front(t_n **lst, t_n *tail);

// ft_lstpoint_print prints the content of a list of t_node_with_a_point
void						ft_lstpoint_print(t_n **lst);

// returns a pointer to the t_node_with_a_point at the i position in the list
t_n							*ft_lstpoint_getby_index(t_n *lst, uint index);

// frees the nodes of a list but not the list itself:
void						ft_lstpoint_free(t_node_with_a_point **list);

// get's the index of the node contating a t_point with specific xyz values
int							lstpoint_getby_content(t_n *n, t_d x, t_d y, t_d z);

// just ft_lstsize but for t_node_with_a_point
int							ft_lstpoint_size(t_node_with_a_point *lst);

// to transform a linked list of ode_with_a_points into a 2d array of t_points
t_point						**ft_lstpoint_toarr(t_n *node, uint width);

#endif
