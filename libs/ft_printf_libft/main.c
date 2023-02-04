/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:50:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:55:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf_libft_includes.h"
#include <stdio.h>
# include "assert.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

int	main(void)
{
	void	*ptr;

	ptr = NULL;
	assert(ft_printf("%s\n", "Hello World") == printf("%s\n", "Hello World"));
	assert(ft_printf("%p\n", &main) == printf("%p\n", &main));
	assert(ft_printf("%p\n", ptr) == printf("%p\n", ptr));
	assert(ft_printf("%Jas\n") == (int)ft_putstr_fd("%Jas\n", 1));
	assert(ft_printf("%Jas\n", "Hello World") == (int)ft_putstr_fd("%Jas\n", 1));
	assert(ft_printf("%d\n", 42) == printf("%d\n", 42));
	assert(ft_printf("%d\n", -42) == printf("%d\n", -42));
	assert(ft_printf("%d\n", 0) == printf("%d\n", 0));
	assert(ft_printf("%d\n", 2147483647) == printf("%d\n", 2147483647));
	assert(ft_printf("%d\n", 42) == printf("%d\n", 42));
	assert(ft_printf("%d\n", -42) == printf("%d\n", -42));
	assert(ft_printf("%d\n", 0) == printf("%d\n", 0));
	assert(ft_printf("%%\n") == printf("%%\n"));
	assert(ft_printf(" %%%% \n") == printf(" %%%% \n"));
}
