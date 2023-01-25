/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_point_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 19:51:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_POINT_BONUS_H
# define FDF_T_POINT_BONUS_H

# include "printf_libft_includes.h"
# include <string.h>

typedef struct s_d	t_data;
typedef struct s_pt	t_point;

static char			*filter_up_to_x(char *current_point);
static void			set_hexcolor(t_point *p, char *s)__attribute__((unused));

typedef struct s_phere
{
	double			phi;
	double			theta;
	double			r;
}					t_sphere;

typedef struct s_raw
{
	short			x;
	short			y;
	short			z;
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

	hexstring = filter_up_to_x(current_p_as_str);
	if (ft_ishexlow(hexstring))
	{
		p->color = ft_atoi_base(hexstring, HEX_BASE);
		return ;
	}
	if (ft_ishexup(hexstring))
	{
		p->color = ft_atoi_base(hexstring, HEX_BASE_UPPER);
		return ;
	}
	hexstring = NULL;
}

static inline char	*filter_up_to_x(char *current_point)
{
	return (ft_strchr(current_point, 'x') + 1);
}

#endif
