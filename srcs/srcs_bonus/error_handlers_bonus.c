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

void	error_handler(void)
{
	printf("%s\n", strerror(22));
	free(get_data()->map);
	free(get_data()->offset);
	free(get_data()->scale);
	free(get_data()->color);
	exit(1);
}

void	uneven_map_error(void)
{
	fclose(get_data()->tool.fp);
	ft_lstpoint_free(&get_data()->map->pts);
	free(get_data()->map);
	free(get_data()->offset);
	free(get_data()->color);
	free(get_data()->scale);
	ft_free_t_split(get_data()->tool.pts_in_this_row);
	printf("%s\n", "Uneven map, first line shouldn't be bigger than the rest");
	exit(1);
}
