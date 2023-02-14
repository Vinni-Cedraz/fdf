/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 12:21:22 by vcedraz-         ###   ########.fr       */
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
typedef struct s_d		t_d;
typedef struct s_is		t_i_changer;
typedef struct s_ctr	t_center;
typedef struct s_nd		t_n;

// GENERAL PURPOSE TYPEDEFS
typedef void			(*t_func_ptr)(t_data *d);
typedef struct s_tmps
{
	double				x;
	double				y;
	double				z;
}						t_emporary;

// FUNCTION PROTOTYPES //
void					data_initializer_bonus(t_data *d);

short					is_a_valid_file(t_data *d);

void					parse_map_bonus(t_data *d);

void					open_win_and_img_bonus(t_data *d);

void					assign_coordinates_bonus(t_data *d);

void					assign_hexcolor_bonus(t_data *d);

void					get_altitude_range_bonus(t_map *map);

void					calculate_default_scale_bonus(t_data *d);

void					define_rotation_matrices_bonus(t_rm *matrix);

void					render_map_bonus(t_data *d);

void					render_line_bonus(t_point p1, t_point p2, t_data *d);

void					render_pentagram(t_data *d);

void					render_lines_square(t_data *d);

void					render_lines_cross(t_data *d);

int						draw_bonus(t_data *d);

int						deal_keys_bonus(int key, t_data *d);

void					transpts_with_given_matrix_bonus(t_data *d, t_m *rot);

void					go_isometric_from_any(t_data *d, t_func_ptr iso_action);

void					loop_through_each_transition_method(t_data *d);

void					go_isometric_from_random_state(t_data *d);

t_m						multiply_two_matrices_bonus(t_m a, t_m b);

void					get_map_dimensions_bonus(t_data *d);

int						close_win_bonus(t_data *data);

void					initialize_lookup_structs_bonus(t_data *d);

void					change_grid_rendering_method(t_data *d);

void					find_map_center_bonus(t_data *d);

void					zoom_in(t_data *d);

void					zoom_in_method(t_data *d);

void					zoom_out(t_data *d);

void					zoom_out_method(t_data *d);

void					reset_zoom_method(t_data *d);

void					take_zoom_snapshot(t_data *d);

void					reset_zoom_from_snapshot(t_data *d);

void					set_t_center_coordinates(t_center *d, t_n *n_center);

int						is_height_even(int height);

int						is_width_even(int width);

int						are_height_and_width_even(t_data *d);

void					rotate_five_around_y(t_data *d);

void					reverse_five_around_y(t_data *d);

void					rotate_five_around_x(t_data *d);

void					reverse_five_around_x(t_data *d);

void					rotate_five_around_z(t_data *d);

void					reverse_five_around_z(t_data *d);

void					go_through_each_stage_of_iso(t_d *d);

void					move_back_to_isometric_state(t_data *d);

void					increase_altitude(t_data *d);

void					decrease_altitude(t_data *d);

void					mirror_altitude(t_data *d);

void					change_altitude_bonus(t_data *d, t_func_ptr method);

void					update_state_after_reset(t_data *d);

void					update_state_after_zoom(t_data *d);

void					take_iso_snapshot(t_data *d);

void					restore_iso_snapshot(t_data *d);

void					go_isometric_using_snapshot(t_data *d);

void					go_to_diagonal(t_data *d);

void					go_to_isometric(t_data *d);

void					undo_isometric(t_data *d);

void					undo_diagonal(t_data *d);

void					call_close_window(t_data *d);

void					go_spherical(t_data *d);

void					get_phi_and_theta(t_data *d);

void					increase_sphere_height(t_data *d);

void					decrease_sphere_height(t_data *d);

void					get_xy_range_bonus(t_data *d);

void					initialize_methods_bonus(t_data *d);

double					calculate_target_width(t_data *d);

void					colorize_points_bonus(t_data *d);

#endif
