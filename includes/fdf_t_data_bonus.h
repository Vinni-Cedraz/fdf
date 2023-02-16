/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_data_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:50:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/16 01:07:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_DATA_BONUS_H
# define FDF_T_DATA_BONUS_H

# include "../libs/ft_printf_libft/libft/libft_bonus.h"
# include "fdf_prototypes_bonus.h"
# include "linked_list_tools.h"
# include "t_lookup_bonus.h"
# include "t_mlx_bonus.h"
# include <stdio.h>

// FORWARD DECLARATIONS (to prevent circular dependencies)
typedef struct s_offset		t_offset;
typedef struct s_color		t_color;
typedef struct s_rm			t_rotation_matrices;
typedef struct s_sc			t_scale;
typedef struct s_pt			t_p;

typedef enum e_state
{
	parallel,
	diagonal,
	isometric,
	randomly_rotated,
	spherical,
}							t_state;

typedef struct s_assign_coordinates
{
	FILE					*fp;
	char					*argv;
	char					*first_line;
	t_split					*pts_in_this_row;
	short					successfully_read;
	char					*p_as_str;
}							t_assign_coordinates;

typedef struct s_d
{
	t_assign_coordinates	tool;
	t_state					state;
	t_emporary				t;
	t_lookup				lookup;
	t_scale					*scale;
	t_offset				*offset;
	t_color					*color;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_rotation_matrices		*matrix;
}							t_data;

#endif
