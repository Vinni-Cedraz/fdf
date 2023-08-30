/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:57:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 22:23:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_BONUS_H
# define FDF_PROTOTYPES_BONUS_H

# define TRUE 1
# define FALSE 0

// FORWARD DECLARATIONS
typedef struct s_mp		t_map;
typedef struct s_pt		t_p;
typedef struct s_m		t_m;
typedef struct s_rm		t_rm;
typedef struct s_zs		t_zscaler;
typedef struct s_d		t_d;
typedef struct s_is		t_i_changer;
typedef struct s_ctr	t_center;
typedef struct s_nd		t_n;
typedef struct s_task	t_task;
typedef struct s_img	t_img;

// GENERAL PURPOSE TYPEDEFS
typedef void			(*t_func_ptr)(void);

typedef struct s_tmps
{
	float				x;
	float				y;
	float				z;
}						t_emporary;

// FUNCTION PROTOTYPES //
void					data_initializer_bonus(void);
short					is_a_valid_file(void);
void					parse_map_bonus(void);
void					open_win_and_img_bonus(void);
void					uneven_map_error(void);
void					assign_coordinates_bonus(void);
void					assign_hexcolor_bonus(void);
void					calculate_default_scale_bonus(void);
void					define_rotation_matrices_bonus(t_rm *matrix);
void					render_map_bonus(void);
void					render_line_bonus(t_p *p1, t_p *p2);
void					render_lines_square(void);
void					render_lines_cross(void);
void					render_lines_pentagram(void);
int						draw_bonus(void);
int						deal_keys_bonus(int key);
void					transpts_with_given_matrix_bonus(t_m *rot);
void					loop_through_each_transition_method(void);
void					go_isometric_from_random_state(void);
t_m						multiply_two_matrices_bonus(t_m a, t_m b);
void					get_map_dimensions_bonus(void);
int						close_win_bonus(void);
void					initialize_lookup_structs_bonus(void);
void					change_grid_rendering_method(void);
void					find_map_center_bonus(void);
void					zoom_in(void);
void					zoom_in_method(void);
void					zoom_out(void);
void					zoom_out_method(void);
void					reset_zoom_method(void);
void					take_zoom_snapshot(void);
void					reset_zoom_from_snapshot(void);
void					set_t_center_coordinates(t_center *c, t_n *n_center);
int						is_height_even(int height);
int						is_width_even(int width);
int						are_height_and_width_even(void);
void					rotate_five_around_y(void);
void					reverse_five_around_y(void);
void					rotate_five_around_x(void);
void					reverse_five_around_x(void);
void					rotate_five_around_z(void);
void					reverse_five_around_z(void);
void					increase_altitude(void);
void					decrease_altitude(void);
void					mirror_altitude(void);
void					change_altitude_bonus(t_func_ptr method);
void					update_state_after_reset(void);
void					update_state_after_zoom(void);
void					restore_iso_snapshot(void);
void					go_isometric_using_snapshot(void);
void					go_to_diagonal(void);
void					go_to_isometric(void);
void					undo_isometric(void);
void					undo_diagonal(void);
void					call_close_window(void);
void					go_spherical(void);
void					get_phi_and_theta(t_p *point);
void					increase_sphere_height(void);
void					decrease_sphere_height(void);
void					get_xyz_range_bonus(void);
void					initialize_methods_bonus(void);
void					colorize_points_bonus(void);
int						max_steps(int dx, int dy);
void					set_hexcolor_bonus(t_p *p, char *p_str);
void					draw_menu(void);
void					error_handler(void);
void					restore_raw_state_bonus(void);
void					normalize_after_leaving_sphere_bonus(void);
void					multi_threaded_workers(t_task actidx);
void					put_pixel_img_bonus(t_img *img, int x, int y, int c);
int						get_img_start_idx(int thread_number);
int						get_img_end_idx(int thread_number);
void					*paint_it_black(t_task *task);
void					*transform_a_point(t_task *task);

#endif
