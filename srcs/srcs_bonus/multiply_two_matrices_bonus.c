/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_two_matrices_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 20:59:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

// seems strange, but look real close and you'll see that it's just a
// step-by-step, very explicit, aplication of a matrix multiplication procedure
// lines had to be split to fit in 80 columns norm, making it weird to read
t_matrix	multiply_two_matrices_bonus(t_matrix a, t_matrix b)
{
	t_matrix	r;

	r.row_1.col_1 = (a.row_1.col_1 * b.row_1.col_1) + \
		(a.row_1.col_2 * b.row_2.col_1) + (a.row_1.col_3 * b.row_3.col_1);
	r.row_1.col_2 = (a.row_1.col_1 * b.row_1.col_2) + \
		(a.row_1.col_2 * b.row_2.col_2) + (a.row_1.col_3 * b.row_3.col_2);
	r.row_1.col_3 = (a.row_1.col_1 * b.row_1.col_3) + \
		(a.row_1.col_2 * b.row_2.col_3) + (a.row_1.col_3 * b.row_3.col_3);
	r.row_2.col_1 = (a.row_2.col_1 * b.row_1.col_1) + \
		(a.row_2.col_2 * b.row_2.col_1) + (a.row_2.col_3 * b.row_3.col_1);
	r.row_2.col_2 = (a.row_2.col_1 * b.row_1.col_2) + \
		(a.row_2.col_2 * b.row_2.col_2) + (a.row_2.col_3 * b.row_3.col_2);
	r.row_2.col_3 = (a.row_2.col_1 * b.row_1.col_3) + \
		(a.row_2.col_2 * b.row_2.col_3) + (a.row_2.col_3 * b.row_3.col_3);
	r.row_3.col_1 = (a.row_3.col_1 * b.row_1.col_1) + \
		(a.row_3.col_2 * b.row_2.col_1) + (a.row_3.col_3 * b.row_3.col_1);
	r.row_3.col_2 = (a.row_3.col_1 * b.row_1.col_2) + \
		(a.row_3.col_2 * b.row_2.col_2) + (a.row_3.col_3 * b.row_3.col_2);
	r.row_3.col_3 = (a.row_3.col_1 * b.row_1.col_3) + \
		(a.row_3.col_2 * b.row_2.col_3) + (a.row_3.col_3 * b.row_3.col_3);
	return (r);
}
