/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 18:58:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

# include "fdf_defines.h"
# include "printf_libft_includes.h"
# include <string.h>

typedef struct s_d	t_data;
typedef struct s_pt	t_point;

static char			*filter_up_to_x(char *current_point);
static char			*check_hexstring(char *hexstring);
static void			set_hexcolor(t_point *p, char *s) __attribute__((unused));

typedef struct s_phere
{
	double			phi;
	double			theta;
	double			rho;
}					t_sphere;

typedef struct s_raw
{
	double			x;
	double			y;
	double			z;
}					t_raw;

typedef struct s_origin
{
	double			x;
	double			y;
	double			z;
	double			zoom_x;
	double			zoom_y;
	double			zoom_z;
	t_raw			raw;
}					t_snapshot;

typedef struct s_pt
{
	double			x;
	double			y;
	double			z;
	long			color;
	t_sphere		ball;
	t_snapshot		ol;
	void			(*set_hexcolor)(t_point *p, char *current_p_as_str);
	void			(*define_p_color_by_altitude)(t_point *p, t_data *d);
}					t_point;

typedef struct s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

static inline void	set_hexcolor(t_point *p, char *current_p_as_str)
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

#endif
