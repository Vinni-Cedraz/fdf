/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/24 18:26:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

// call the function in the current node of grid_methods
void	render_map_bonus(void)
{
	((t_func_ptr)(get_data()->lookup.grid_methods->content))();
}

// iterate to the next node in the grid_methods list
void	change_grid_rendering_method(void)
{
	get_data()->lookup.grid_methods = get_data()->lookup.grid_methods->next;
}

// the following functions are the grid_methods:
void	render_lines_square(void)
{
	multi_threaded_iter((t_action_and_idx){.action = render_square});
}

void	render_lines_cross(void)
{
	render_lines_square();
	multi_threaded_iter((t_action_and_idx){.action = render_cross});
}

void	render_lines_pentagram(void)
{
	multi_threaded_iter((t_action_and_idx){.action = render_pentagram});
}
