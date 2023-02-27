/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:24:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 17:25:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	error_handler(t_data *d)
{
	printf("%s\n", strerror(22));
	free(d->map);
	free(d->offset);
	free(d->scale);
	free(d->color);
	free(d);
	exit(1);
}

void	uneven_map_error(t_data *d)
{
	fclose(d->tool.fp);
	ft_lstpoint_free(&d->map->pts);
	free(d->map);
	free(d->offset);
	free(d->color);
	free(d->scale);
	ft_free_t_split(d->tool.pts_in_this_row);
	free(d);
	printf("%s\n", "Uneven map, first line shouldn't be bigger than the rest");
	exit(1);
}
