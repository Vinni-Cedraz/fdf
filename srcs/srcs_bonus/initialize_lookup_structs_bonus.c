/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_lookup_structs_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:05:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/31 16:56:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	initialize_transition_methods(t_data *d);
static void	initialize_grid_methods(t_data *d);
static void	initialize_key_events_table(t_data *d);

void	initialize_lookup_structs_bonus(t_data *d)
{
	initialize_transition_methods(d);
	initialize_grid_methods(d);
	initialize_key_events_table(d);
}

static void	initialize_transition_methods(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&go_to_diagonal);
	ft_lstadd_back(&head, ft_lstnew(&go_to_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_diagonal));
	ft_lst_make_it_circular(&head);
	d->lookup.iso_transit_methods = head;
}

static void	initialize_grid_methods(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&render_lines_square);
	ft_lstadd_back(&head, ft_lstnew(&render_lines_cross));
	ft_lstadd_back(&head, ft_lstnew(&render_pentagram));
	ft_lst_make_it_circular(&head);
	d->lookup.grid_methods = head;
}

static void	initialize_key_events_table(t_data *d)
{
	d->lookup.events = ft_calloc(128, sizeof(void *));
	d->lookup.events['h'] = (t_func_ptr){&left};
	d->lookup.events['l'] = (t_func_ptr){&right};
	d->lookup.events['k'] = (t_func_ptr){&up};
	d->lookup.events['j'] = (t_func_ptr){&down};
	d->lookup.events['w'] = (t_func_ptr){&zoom_in};
	d->lookup.events['s'] = (t_func_ptr){&zoom_out};
	d->lookup.events['d'] = (t_func_ptr){&rotate_five_around_y};
	d->lookup.events['a'] = (t_func_ptr){&reverse_five_around_y};
	d->lookup.events['e'] = (t_func_ptr){&rotate_five_around_x};
	d->lookup.events['q'] = (t_func_ptr){&reverse_five_around_x};
	d->lookup.events['v'] = (t_func_ptr){&rotate_five_around_z};
	d->lookup.events['x'] = (t_func_ptr){&reverse_five_around_z};
	d->lookup.events['z'] = (t_func_ptr){&increase_altitude};
	d->lookup.events['c'] = (t_func_ptr){&decrease_altitude};
	d->lookup.events['m'] = (t_func_ptr){&mirror_altitude};
	d->lookup.events[' '] = (t_func_ptr){&go_through_each_stage_of_iso};
	d->lookup.events['g'] = (t_func_ptr){&change_grid_rendering_method};
	d->lookup.events[';'] = (t_func_ptr){&move_back_to_isometric_state};
}
