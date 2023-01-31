/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_two_matrices_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/30 20:34:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_row			multiply_row_matrix(t_row row, t_matrix b);
static t_column			get_matrix_column(int col, t_matrix m);

t_matrix	multiply_two_matrices_bonus(t_matrix a, t_matrix b)
{
	t_matrix	final_matrix;

	final_matrix.row_1 = multiply_row_matrix(a.row_1, b);
	final_matrix.row_2 = multiply_row_matrix(a.row_2, b);
	final_matrix.row_3 = multiply_row_matrix(a.row_3, b);
	return (final_matrix);
}

static inline t_row	multiply_row_matrix(t_row row, t_matrix m)
{
	t_row		final_row;
	t_column	m_col;

	m_col = get_matrix_column(1, m);
	final_row.a = (row.a * m_col.a) + (row.b * m_col.b) + (row.c * m_col.c);
	m_col = get_matrix_column(2, m);
	final_row.b = (row.a * m_col.a) + (row.b * m_col.b) + (row.c * m_col.c);
	m_col = get_matrix_column(3, m);
	final_row.c = (row.a * m_col.a) + (row.b * m_col.b) + (row.c * m_col.c);
	return (final_row);
}

static inline t_column	get_matrix_column(int col, t_matrix m)
{
	t_column	m_col[3];

	m_col[0] = (t_column){m.row_1.a, m.row_2.a, m.row_3.a};
	m_col[1] = (t_column){m.row_1.b, m.row_2.b, m.row_3.b};
	m_col[2] = (t_column){m.row_1.c, m.row_2.c, m.row_3.c};
	return (m_col[col - 1]);
}
