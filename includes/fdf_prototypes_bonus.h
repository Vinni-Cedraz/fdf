/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 11:34:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADER GUARD
#ifndef FDF_PROTOTYPES_BONUS_H
# define FDF_PROTOTYPES_BONUS_H

// FORWARD DECLARATIONS
typedef struct s_mp	t_map;
typedef struct s_pt	t_point;
typedef struct s_m	t_m;
typedef struct s_rm	t_rotation_matrices;
typedef struct s_zs	t_zscaler;
typedef struct s_d	t_data;
typedef struct s_is	t_i_changer;

// FUNCTION PROTOTYPES //
void				data_initializer_bonus(t_data *d);

int					parse_map_bonus(t_data *d);

void				assign_coordinates_bonus(t_data *d);

void				get_and_assign_hexcolor_bonus(t_data *d);

void				get_altitude_range_bonus(t_map *map);

void				calculate_default_scale_bonus(t_data *d, int size);

void				define_rotation_matrices_bonus(t_rotation_matrices *matrix);

void				render_line_bonus(t_point p1, t_point p2, t_data *d);

void				render_map_bonus(t_data *d, int sqr, int cross, int pent);

void				colorize_points_bonus(t_data *d);

int					draw_bonus(t_data *d);

int					deal_keys_bonus(int key, t_data *d);

void				zoom_bonus(t_data *d, int in, int out, int reset);

void				transpts_with_given_matrix_bonus(t_data *d, t_m *rot);

void				two_steps_to_isometry_bonus(t_data *d, t_i_changer changer);

t_m					multiply_two_matrices_bonus(t_m a, t_m b);

void				change_altitude_bonus(t_data *d, t_zscaler direction);

int					close_win_bonus(t_data *data);

#endif
