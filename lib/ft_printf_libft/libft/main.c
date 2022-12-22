/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:31:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/22 18:46:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char *file;
	int fd;
	int integer;
	
	(void)argc;
	integer = 0;
	fd = open(*++argv, O_RDONLY);
	do {
		file = ft_gnl(fd);
		ft_printf("%d ", integer);
		ft_putstr(file);
		integer++;
	} while (file);
}
