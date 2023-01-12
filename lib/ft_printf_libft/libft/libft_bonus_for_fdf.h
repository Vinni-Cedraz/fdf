/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus_for_fdf.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:07:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 16:25:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_FOR_FDF_H
# define LIBFT_BONUS_FOR_FDF_H

# include "../../../includes/t_point_bonus.h"
# include <stdlib.h>

typedef t_node_with_a_point	t_n;
typedef double				t_d;

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

#endif
