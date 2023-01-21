/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_two_matrices_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 14:23:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_row			multiply_row_matrix(t_row vec, t_matrix b);
static t_vector			get_matrix_column(t_matrix m, int col);

t_matrix	multiply_two_matrices_bonus(t_matrix a, t_matrix b)
{
	t_matrix	final_matrix;

	final_matrix.row_1 = multiply_row_matrix(a.row_1, b);
	final_matrix.row_2 = multiply_row_matrix(a.row_2, b);
	final_matrix.row_3 = multiply_row_matrix(a.row_3, b);
	return (final_matrix);
}

static inline t_row	multiply_row_matrix(t_row r, t_matrix m)
{
	t_row		final_row;
	t_vector	col;

	col = get_matrix_column(m, 1);
	final_row.col_1 = (r.col_1 * col.x) + (r.col_2 * col.y) + (r.col_3 * col.z);
	col = get_matrix_column(m, 2);
	final_row.col_2 = (r.col_1 * col.x) + (r.col_2 * col.y) + (r.col_3 * col.z);
	col = get_matrix_column(m, 3);
	final_row.col_3 = (r.col_1 * col.x) + (r.col_2 * col.y) + (r.col_3 * col.z);
	return (final_row);
}

static inline t_vector	get_matrix_column(t_matrix m, int col)
{
	t_vector	m_col[3];

	m_col[0] = (t_vector){m.row_1.col_1, m.row_2.col_1, m.row_3.col_1};
	m_col[1] = (t_vector){m.row_1.col_2, m.row_2.col_2, m.row_3.col_2};
	m_col[2] = (t_vector){m.row_1.col_3, m.row_2.col_3, m.row_3.col_3};
	return (m_col[col - 1]);
}
