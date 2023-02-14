/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexcolor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:17:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 20:20:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static char			*filter_up_to_x(char *current_point);
static char			*check_hexstring(char *hexstring);

void	set_hexcolor_bonus(t_point *p, char *current_p_as_str)
{
	char	*hexstring;
	char	*base;

	hexstring = filter_up_to_x(current_p_as_str);
	base = check_hexstring(hexstring);
	if (base)
		p->color = ft_atoi_base(hexstring, base);
	else
		p->color = CYAN;
}

static inline char	*filter_up_to_x(char *current_point)
{
	char	*comma;

	comma = ft_strchr(current_point, ',');
	if (!comma)
		return (NULL);
	return (comma + 3);
}

static inline char	*check_hexstring(char *hexstring)
{
	if (ft_ishexlow(hexstring))
		return (HEX_BASE_LOWER);
	if (ft_ishexup(hexstring))
		return (HEX_BASE_UPPER);
	return (NULL);
}
