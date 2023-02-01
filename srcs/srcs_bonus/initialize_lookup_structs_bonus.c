/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_lookup_structs_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:05:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/31 22:37:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	initialize_transition_methods(t_data *d);
static void	initialize_grid_methods(t_data *d);
static void	initialize_key_events_table(t_data *d);

void	initialize_lookup_structs_bonus(t_data *d)
{
	d->lookup.set_hash = &hash_f;
	initialize_transition_methods(d);
	initialize_grid_methods(d);
	initialize_key_events_table(d);
	d->lookup.set_hash(d->lookup.events);
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
	d->lookup.events = ft_calloc(128, sizeof(t_event));
	d->lookup.events[0] = (t_event){XK_ESCAPE, &close_window};
	d->lookup.events[1] = (t_event){'h', &left};
	d->lookup.events[2] = (t_event){'l', &right};
	d->lookup.events[3] = (t_event){'k', &up};
	d->lookup.events[4] = (t_event){'j', &down};
	d->lookup.events[5] = (t_event){'w', &zoom_in};
	d->lookup.events[6] = (t_event){'s', &zoom_out};
	d->lookup.events[7] = (t_event){'d', &rotate_five_around_y};
	d->lookup.events[8] = (t_event){'a', &reverse_five_around_y};
	d->lookup.events[9] = (t_event){'e', &rotate_five_around_x};
	d->lookup.events[10] = (t_event){'q', &reverse_five_around_x};
	d->lookup.events[11] = (t_event){'v', &rotate_five_around_z};
	d->lookup.events[12] = (t_event){'x', &reverse_five_around_z};
	d->lookup.events[13] = (t_event){'z', &increase_altitude};
	d->lookup.events[14] = (t_event){'c', &decrease_altitude};
	d->lookup.events[15] = (t_event){'m', &mirror_altitude};
	d->lookup.events[16] = (t_event){' ', &go_through_each_stage_of_iso};
	d->lookup.events[17] = (t_event){'g', &change_grid_rendering_method};
	d->lookup.events[18] = (t_event){';', &move_back_to_isometric_state};
	d->lookup.events[19] = (t_event){XK_LEFT, &left};
	d->lookup.events[20] = (t_event){XK_RIGHT, &right};
	d->lookup.events[21] = (t_event){XK_UP, &up};
	d->lookup.events[22] = (t_event){XK_DOWN, &down};
}
