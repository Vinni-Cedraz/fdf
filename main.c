/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:27:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/08 18:42:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf_libft/includes/printf_libft_includes.h"

int	main(void)
{
	t_split	*split;
	int		word;

	split = ft_split("00 01 21 02 12", ' ');
	word = split->words;
	while (word--)
		ft_printf("%d\n", ft_atoi(split->str_arr[word]));
	ft_printf("this is the number of lines:%d\n", split->words);
	ft_free_arr(split->str_arr, (void **)split->str_arr);
}
