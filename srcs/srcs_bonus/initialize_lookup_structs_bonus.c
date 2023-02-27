/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_lookup_structs_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:05:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 22:45:56 by vcedraz-         ###   ########.fr       */
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
	d->lookup.set_event_index_by_key(d->lookup.events);
}

static void	initialize_transition_methods(t_data *d)
{
	t_node	*head;

	head = ft_lstnew(&go_to_diagonal);
	ft_lstadd_back(&head, ft_lstnew(&go_to_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_isometric));
	ft_lstadd_back(&head, ft_lstnew(&undo_diagonal));
	ft_lst_make_it_circular(&head);
	d->lookup.transition_methods = head;
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
	t_event	*events;

	events = d->lookup.events;
	events[0] = (t_event){ESC, &call_close_window};
	events[1] = (t_event){'k', &increase_sphere_height};
	events[2] = (t_event){'j', &decrease_sphere_height};
	events[3] = (t_event){'b', &go_spherical};
	events[4] = (t_event){'w', &zoom_in};
	events[5] = (t_event){'s', &zoom_out};
	events[6] = (t_event){'d', &rotate_five_around_y};
	events[7] = (t_event){'a', &reverse_five_around_y};
	events[8] = (t_event){'e', &rotate_five_around_x};
	events[9] = (t_event){'q', &reverse_five_around_x};
	events[10] = (t_event){'v', &rotate_five_around_z};
	events[11] = (t_event){'x', &reverse_five_around_z};
	events[12] = (t_event){'z', &increase_altitude};
	events[13] = (t_event){'c', &decrease_altitude};
	events[14] = (t_event){'m', &mirror_altitude};
	events[15] = (t_event){' ', &loop_through_each_transition_method};
	events[16] = (t_event){'g', &change_grid_rendering_method};
	events[17] = (t_event){';', &go_isometric_using_snapshot};
	events[18] = (t_event){UP_ARROW, d->offset->move[0]};
	events[19] = (t_event){DOWN_ARROW, d->offset->move[1]};
	events[20] = (t_event){LEFT_ARROW, d->offset->move[2]};
	events[21] = (t_event){RIGHT_ARROW, d->offset->move[3]};
}
