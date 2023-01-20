/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_two_matrices_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 23:46:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_row		get_first_row(t_matrix a, t_matrix b);
static t_row		get_second_row(t_matrix a, t_matrix b);
static t_row		get_third_row(t_matrix a, t_matrix b);

t_matrix	multiply_two_matrices_bonus(t_matrix a, t_matrix b)
{
	t_matrix	result;

	result.row_1 = get_first_row(a, b);
	result.row_2 = get_second_row(a, b);
	result.row_3 = get_third_row(a, b);
	return (result);
}

static inline t_row	get_first_row(t_matrix a, t_matrix b)
{
	t_row	first_row;

	first_row.col_1 = a.row_1.col_1 * b.row_1.col_1 + a.row_1.col_2
		* b.row_2.col_1 + a.row_1.col_3 * b.row_3.col_1;
	first_row.col_2 = a.row_1.col_1 * b.row_1.col_2 + a.row_1.col_2
		* b.row_2.col_2 + a.row_1.col_3 * b.row_3.col_2;
	first_row.col_3 = a.row_1.col_1 * b.row_1.col_3 + a.row_1.col_2
		* b.row_2.col_3 + a.row_1.col_3 * b.row_3.col_3;
	return (first_row);
}

static inline t_row	get_second_row(t_matrix a, t_matrix b)
{
	t_row	second_row;

	second_row.col_1 = a.row_2.col_1 * b.row_1.col_1 + a.row_2.col_2
		* b.row_2.col_1 + a.row_2.col_3 * b.row_3.col_1;
	second_row.col_2 = a.row_2.col_1 * b.row_1.col_2 + a.row_2.col_2
		* b.row_2.col_2 + a.row_2.col_3 * b.row_3.col_2;
	second_row.col_3 = a.row_2.col_1 * b.row_1.col_3 + a.row_2.col_2
		* b.row_2.col_3 + a.row_2.col_3 * b.row_3.col_3;
	return (second_row);
}

static inline t_row	get_third_row(t_matrix a, t_matrix b)
{
	t_row	third_row;

	third_row.col_1 = a.row_3.col_1 * b.row_1.col_1 + a.row_3.col_2
		* b.row_2.col_1 + a.row_3.col_3 * b.row_3.col_1;
	third_row.col_2 = a.row_3.col_1 * b.row_1.col_2 + a.row_3.col_2
		* b.row_2.col_2 + a.row_3.col_3 * b.row_3.col_2;
	third_row.col_3 = a.row_3.col_1 * b.row_1.col_3 + a.row_3.col_2
		* b.row_2.col_3 + a.row_3.col_3 * b.row_3.col_3;
	return (third_row);
}
