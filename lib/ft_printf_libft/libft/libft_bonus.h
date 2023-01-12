/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:49:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "../../../includes/t_point_bonus.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define FIXED_BUFSZ 10000

typedef struct s_nodes	t_node;

typedef struct s_mod
{
	short				read_failed;
	char				*buf;
	int					l_bgn;
	int					l_end;
	int					l_sz;
	int					read;
}						t_mod;

typedef struct s_nodes
{
	void				*content;
	t_node				*next;
}						t_node;

// LINKED LISTS BASIC FUNCTIONS
// ft_lstnew creates a new node
t_node					*ft_lstnew(void *content);
// ads a node
t_node_with_a_point		*ft_lstpoint_new(void);
// ft_lstadd_back adds a new element at the end of a list
void					ft_lstadd_back(t_node **head, t_node *new_node);
// ft_lstpoint_back	adds a t_node_with_a_point to the end of a list
void	ft_lstpoint_back(t_node_with_a_point **head,
						t_node_with_a_point *new_node);
// ft_lstadd_front adds a new element at the beginning of a list
void					ft_lstadd_front(t_node **head, t_node *new_node);
// ft_lstpoint_front adds a t_node_with_a_point to the beginning of a list
void					ft_lstpoint_front(t_node_with_a_point **head,
						t_node_with_a_point *new_node);
// ft_lstfree frees each node in a list and frees the list itself at the end
void					ft_lstfree(t_node **list);

// LINKED LISTS SPECIFIC OPERATIONS
// ft_lstlast returns the last element of the list
t_node					*ft_lstlast(t_node *first_node);
// ft_lstsize returns the number of elements in a list
int						ft_lstsize(t_node *first_node);
// ft_lst_print prints the content of a list
void					ft_lstprint(t_node **lst);
// ft_lstpoint_print prints the content of a list of t_node_with_a_point
void					ft_lstpoint_print(t_node_with_a_point **lst);
// adds a node at a specific position in the list and returns a pointer to it
t_node					*ft_lstadd_here(t_node **lst, t_node *n, uint index);
// del a node at a given index
void					ft_lstdel_here(t_node **lst, uint index);
// returns a pointer to the node at the index position in the list
t_node					*ft_lstgetby_index(t_node *lst, uint index);
// returns a pointer to the t_node_with_a_point at the index position in the list
t_node_with_a_point		*ft_lstpoint_getby_index(t_node_with_a_point *lst,
												uint index);
// returns the index at which a given content is found within a list
int						ft_lstgetby_content(t_node *lst, void *content);
// returns the index at which a given z value is found within the contents of the t_node_with_a_point's list
// frees the nodes of a list but not the list itself:
void					ft_lstpoint_free(t_node_with_a_point **list);
// frees the first node of a list
t_node					*ft_lstshift(t_node **lst);
// frees the last node of a list
void					ft_lstpop(t_node **lst);

//  FORBIDDEN FUNCTIONS, USE ONLY WHEN THE BONUS ALLOWS ANY FUNCTION
// ft_special_gnl is a faster gnl with fread, fopen and a fixed buffersize
char					*ft_special_gnl(FILE *fp);

#endif
