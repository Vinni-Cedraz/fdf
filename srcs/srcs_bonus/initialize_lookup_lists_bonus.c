/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_lookup_lists_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:05:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 18:10:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			initialize_transition_methods(t_data *d);
static void			initialize_grid_methods(t_data *d);

void	initialize_lookup_lists_bonus(t_data *d)
{
	initialize_transition_methods(d);
	initialize_grid_methods(d);
}

static inline void	initialize_transition_methods(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&go_to_diagonal);
	ft_lstadd_back(&head, ft_lstnew(&go_to_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_diagonal));
	ft_lst_make_it_circular(&head);
	d->lookup.iso_transit_methods = head;
}

static inline void	initialize_grid_methods(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&render_lines_square);
	ft_lstadd_back(&head, ft_lstnew(&render_lines_cross));
	ft_lstadd_back(&head, ft_lstnew(&render_pentagram));
	ft_lst_make_it_circular(&head);
	d->lookup.grid_methods = head;
}
