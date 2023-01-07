/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:55:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 12:57:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stdio.h>
# include <pthread.h>

typedef struct s_nodes
{
	void				*content;
	struct s_nodes		*next;
}						t_node;

// LINKED LISTS:

// ft_lstadd_back adds a new element at the end of a list:
void	ft_lstadd_back(t_node **first_node, t_node *new_node);
// ft_lstadd_front adds a new element at the beginning of a list:
void	ft_lstadd_front(t_node **first_node, t_node *new_node);
// ft_lstdel_one deletes a node from a list:
void	ft_lstdel_one(t_node *first_node, void (*del)(void *));
// ft_lstdel_each_one deletes and frees the given element and it's successors
void	ft_lstdel_each_one(t_node **first_node, void (*del)(void *));
// ft_lstlast returns the last element of the list:
t_node	*ft_lstlast(t_node *first_node);
// ft_lstnew creates a new element:
t_node	*ft_lstnew(void *content);
// ft_lstsize returns the number of elements in a list:
int		ft_lstsize(t_node *first_node);
// ft_free_list frees each node in a list and frees the list itself at the end
void	ft_lstfree(t_node **list);
// ft_delnode_content sets the content of a node to NULL;
void	ft_lstnull_node(void *node);
// ft_lst_print prints the content of a list:
void	ft_lstprint(t_node *lst);
// ft_special_gnl is a faster gnl with forbidden functions:
char	*ft_special_gnl(FILE *fp);

#endif
