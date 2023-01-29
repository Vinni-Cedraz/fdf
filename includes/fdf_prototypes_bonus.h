/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 12:07:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_BONUS_H
# define FDF_PROTOTYPES_BONUS_H

// FORWARD DECLARATIONS
typedef struct s_mp		t_map;
typedef struct s_pt		t_point;
typedef struct s_m		t_m;
typedef struct s_rm		t_rm;
typedef struct s_zs		t_zscaler;
typedef struct s_d		t_data;
typedef struct s_is		t_i_changer;
typedef struct s_ctr	t_center;
typedef struct s_nd		t_n;
typedef void			(*t_func_ptr)(t_data *d);

// FUNCTION PROTOTYPES //
void					data_initializer_bonus(t_data *d);

int						parse_map_bonus(t_data *d);

void					open_win_and_img_bonus(t_data *d);

void					assign_coordinates_bonus(t_data *d);

int						assign_hexcolor_bonus(t_data *d);

void					get_altitude_range_bonus(t_map *map);

void					calculate_default_scale_bonus(t_data *d);

void					define_rotation_matrices_bonus(t_rm *matrix);

void					render_map_bonus(t_data *d);

void					render_line_bonus(t_point p1, t_point p2, t_data *d);

void					render_pentagram(t_data *d);

void					render_lines_square(t_data *d);

void					render_lines_cross(t_data *d);

void					colorize_points_bonus(t_data *d);

int						draw_bonus(t_data *d);

int						deal_keys_bonus(int key, t_data *d);

void					zoom_bonus(t_data *d, t_func_ptr zoom_method);

void					transpts_with_given_matrix_bonus(t_data *d, t_m *rot);

void					two_steps_to_isometry_bonus(t_data *d, t_i_changer c);

t_m						multiply_two_matrices_bonus(t_m a, t_m b);

void					change_altitude_bonus(t_data *d, t_zscaler direction);

void					compute_color_gradient_bonus(t_point *p, t_data *d);

void					get_map_dimensions_bonus(t_data *d);

int						close_win_bonus(t_data *data);

void					assign_t_points_methods_bonus(t_data *d);

void					initialize_lookup_lists_bonus(t_data *d);

void					change_grid_rendering_method(t_data *d);

void					find_map_center_bonus(t_data *d);

void					zoom_in(t_data *d);

void					zoom_out(t_data *d);

void					take_zoom_snapshot(t_data *d);

void					restore_zoom_from_snapshot(t_data *d);

void					set_t_center_coordinates(t_center *d, t_n *n_center);

int						is_height_even(int height);

int						is_width_even(int width);

int						are_height_and_width_even(t_data *d);

void					reset_states(t_data *d);

void					rotate_five_around_x(t_data *d);

void					reverse_five_around_x(t_data *d);

void					rotate_five_around_z(t_data *d);

void					reverse_five_around_z(t_data *d);
#endif
