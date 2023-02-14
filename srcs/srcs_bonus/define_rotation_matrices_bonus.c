/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rotation_matrices_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:18:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 20:47:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

typedef t_matrix	(*t_mul_mat)(t_matrix, t_matrix);

static void	define_free_rotation_matrices(t_rotation_matrices *matrix);
static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix);
static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix);
static void	define_change_altitude_matrix(t_rotation_matrices *matrix);

void	define_rotation_matrices_bonus(t_rotation_matrices *matrix)
{
	define_free_rotation_matrices(matrix);
	define_isometry_step_one_rotation(matrix);
	define_isometry_step_two_rotation(matrix);
	matrix->iso_in_one_step = &iso_in_one_step;
	matrix->scale_z_up_tmp_stage = &scale_z_up_tmp_stage;
	define_change_altitude_matrix(matrix);
}

static void	define_free_rotation_matrices(t_rotation_matrices *matrix)
{
	matrix->rev_x = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD), sin(RAD)},
	{0, -sin(RAD), cos(RAD)}};
	matrix->rev_y = (t_matrix){
	{cos(RAD), 0, -sin(RAD)},
	{0, 1, 0},
	{sin(RAD), 0, cos(RAD)}};
	matrix->rev_z = (t_matrix){
	{cos(RAD), sin(RAD), 0},
	{-sin(RAD), cos(RAD), 0},
	{0, 0, 1}};
	matrix->rot_x = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD), -sin(RAD)},
	{0, sin(RAD), cos(RAD)}};
	matrix->rot_y = (t_matrix){
	{cos(RAD), 0, sin(RAD)},
	{0, 1, 0},
	{-sin(RAD), 0, cos(RAD)}};
	matrix->rot_z = (t_matrix){
	{cos(RAD), -sin(RAD), 0},
	{sin(RAD), cos(RAD), 0},
	{0, 0, 1}};
}

static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_z_45 = (t_matrix){
	{cos(RAD_45), sin(RAD_45), 0},
	{-sin(RAD_45), cos(RAD_45), 0},
	{0, 0, 1}};
	matrix->rev_z_45 = (t_matrix){
	{cos(RAD_45), -sin(RAD_45), 0},
	{sin(RAD_45), cos(RAD_45), 0},
	{0, 0, 1}};
}

static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_x_54_73 = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD_54_73), sin(RAD_54_73)},
	{0, -sin(RAD_54_73), cos(RAD_54_73)}};
	matrix->rev_x_54_73 = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD_54_73), -sin(RAD_54_73)},
	{0, sin(RAD_54_73), cos(RAD_54_73)}};
}

static void	define_change_altitude_matrix(t_rotation_matrices *m)
{
	m->pre_change_altitude_up = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1.1}};
	m->pre_change_altitude_down = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 0.9}};
	m->pre_change_altitude_mirror = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, -1}};
	m->iso_in_one_step(m);
	m->scale_z_up_tmp_stage(m);
	m->change_altitude_up = m->mul_mat(m->undo_iso_do_pre_up, m->go_iso);
	m->change_altitude_down = m->mul_mat(m->undo_iso_do_pre_down, m->go_iso);
	m->change_altitude_mirr = m->mul_mat(m->undo_iso_do_pre_mirror, m->go_iso);
}
