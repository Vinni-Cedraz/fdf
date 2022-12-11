/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:27:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/11 08:46:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf_libft/includes/printf_libft_includes.h"

int	main(void)
{
	t_split	*split;
	int		word;

	word = -1;
	split = ft_split("00 01 21 02 12", ' ');
	while (word++ < (int)split->words - 1)
		ft_printf("%d\n", ft_atoi(split->str_arr[word]));
	ft_printf("this is the number of lines:%d\n", split->words);
	ft_printf("this number was passed as a hexcode: %d\n", 0x0FFFFFFF);
	ft_free_t_split(split);
}
