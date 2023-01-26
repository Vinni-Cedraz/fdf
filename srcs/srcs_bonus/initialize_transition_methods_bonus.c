/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_transition_methods_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:02:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 23:54:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	initialize_transition_methods_bonus(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&go_to_diagonal);
	ft_lstadd_back(&head, ft_lstnew(&go_to_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_diagonal));
	ft_lst_make_it_circular(&head);
	d->state_transition_methods = head;
}
