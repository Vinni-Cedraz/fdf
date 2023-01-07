/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:31:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 13:00:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

// int	main(int argc, char **argv)
// {
// 	char	*file;
// 	int		fd;
//
// 	(void)argc;
// 	fd = open(*++argv, O_RDONLY);
// 	file = ft_gnl(fd);
// 	while (file)
// 	{
// 		ft_putstr(file);
// 		file = ft_gnl(fd);
// 	}
// 	return (0);
// }

int main(void)
{
	t_node *node;
	
	node = ft_lstnew("World");
	ft_lstadd_front(&node, ft_lstnew("Hello"));
	ft_lstprint(node);
}
