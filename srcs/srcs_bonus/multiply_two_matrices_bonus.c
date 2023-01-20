/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_two_matrices_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/20 14:23:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_row		transform_vector(t_row vec, t_matrix b);

// treats each row of matrix "a" as a vector to be transformed by matrix "b"
t_matrix	multiply_two_matrices_bonus(t_matrix a, t_matrix b)
{
	t_matrix	final_matrix;

	final_matrix.row_1 = transform_vector(a.row_1, b);
	final_matrix.row_2 = transform_vector(a.row_2, b);
	final_matrix.row_3 = transform_vector(a.row_3, b);
	return (final_matrix);
}

//multiplies a's first row by all three columns of b
static inline t_row	transform_vector(t_row vec, t_matrix m)
{
	t_row		final_vector;
	t_emporary	v;
	t_emporary	m_col1;
	t_emporary	m_col2;
	t_emporary	m_col3;

	v = (t_emporary){vec.col_1, vec.col_2, vec.col_3};
	m_col1 = (t_emporary){m.row_1.col_1, m.row_2.col_1, m.row_3.col_1};
	m_col2 = (t_emporary){m.row_1.col_2, m.row_2.col_2, m.row_3.col_2};
	m_col3 = (t_emporary){m.row_1.col_3, m.row_2.col_3, m.row_3.col_3};
	final_vector.col_1 = (v.x * m_col1.x) + (v.y * m_col1.y) + (v.z * m_col1.z);
	final_vector.col_2 = (v.x * m_col2.x) + (v.y * m_col2.y) + (v.z * m_col2.z);
	final_vector.col_3 = (v.x * m_col3.x) + (v.y * m_col3.y) + (v.z * m_col3.z);
	return (final_vector);
}
