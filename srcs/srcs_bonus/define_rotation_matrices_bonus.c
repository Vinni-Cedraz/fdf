/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rotation_matrices_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:18:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 10:49:30 by vcedraz-         ###   ########.fr       */
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
	matrix->scaling_z_up = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1.1}};
	matrix->scaling_z_down = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 0.9}};
	matrix->scaling_z_mirror = (t_matrix){
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, -1}};
	define_free_rotation_matrices(matrix);
	define_isometry_step_one_rotation(matrix);
	define_isometry_step_two_rotation(matrix);
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
	t_matrix	scaled_up;
	t_matrix	scaling_z_down;
	t_matrix	mirrored;
	t_mul_mat	mul_matrices;

	mul_matrices = &multiply_two_matrices_bonus;
	m->undo_iso = mul_matrices(m->rev_x_54_73, m->rev_z_45);
	m->go_iso = mul_matrices(m->rot_z_45, m->rot_x_54_73);
	scaled_up = mul_matrices(m->undo_iso, m->scaling_z_up);
	scaling_z_down = mul_matrices(m->undo_iso, m->scaling_z_down);
	mirrored = mul_matrices(m->undo_iso, m->scaling_z_mirror);
	m->change_altitude_up = mul_matrices(scaled_up, m->go_iso);
	m->change_altitude_down = mul_matrices(scaling_z_down, m->go_iso);
	m->change_altitude_mirror = mul_matrices(mirrored, m->go_iso);
}
