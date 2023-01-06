/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:31:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 18:39:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		fd;

	(void)argc;
	fd = open(*++argv, O_RDONLY);
	file = ft_gnl(fd);
	while (file)
	{
		ft_putstr(file);
		file = ft_gnl(fd);
	}
	return (0);
}
