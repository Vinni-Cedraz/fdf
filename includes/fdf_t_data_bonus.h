/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_data_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/08 11:35:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_DATA_BONUS_H
# define FDF_T_DATA_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "../libs/ft_printf_libft/libft/libft_bonus.h"
# include "linked_list_tools.h"
# include "t_event_bonus.h"
# include "t_mlx_bonus.h"
# include <stdio.h>

// FORWARD DECLARATIONS (to prevent circular dependencies)
typedef struct s_offset		t_offset;
typedef struct s_color		t_color;
typedef struct s_rm			t_rotation_matrices;

typedef enum e_state
{
	parallel,
	diagonal,
	isometric,
	randomly_rotated,
	spherical,
}							t_state;

typedef struct s_d
{
	t_assign_coordinates	tool;
	t_state					state;
	t_offset				*offset;
	t_emporary				t;
	t_color					*c;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_rotation_matrices		*matrix;
	t_lookup				lookup;
}							t_data;

#endif
