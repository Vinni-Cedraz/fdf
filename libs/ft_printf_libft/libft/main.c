/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:31:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 19:26:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//gnl test
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

// linked lists tests
// static void	list_init(t_node **node);
// static void	special_list_init(t_node **node);
//
// int	main(void)
// {
// 	t_node	**lst;
// 	char	*str;
//
// 	lst = malloc(sizeof(t_node *));
// 	list_init(lst);
// 	printf("original list :\n");
// 	ft_lstprint(lst);
// 	ft_lstdel_here(lst, 0);
// 	printf("\n\n list after del at index 0: \n");
// 	ft_lstprint(lst);
// 	printf("\n\n list ater del at index 2: \n");
// 	ft_lstdel_here(lst, 2);
// 	ft_lstprint(lst);
// 	printf("\n\n list after insert at index 2: \n");
// 	ft_lstadd_here(lst, ft_lstnew("How"), 2);
// 	ft_lstprint(lst);
// 	printf("\n\n content of the node at index 5: \n");
// 	str = ft_lstgetby_index(*lst, 5)->content;
// 	ft_putstr(str);
// 	printf("\n\n content of the node at index 2: \n");
// 	str = ft_lstgetby_index(*lst, 2)->content;
// 	ft_putstr(str);
// 	printf("\n\n list after shift operation: \n");
// 	ft_lstshift(lst);
// 	ft_lstprint(lst);
// 	printf("\n\n list after pop operation: \n");
// 	ft_lstpop(lst);
// 	ft_lstprint(lst);
// 	printf("\n\n list after adding them again: \n");
// 	ft_lstadd_back(lst, ft_lstnew("?"));
// 	ft_lstadd_front(lst, ft_lstnew("Hello"));
// 	ft_lstprint(lst);
// 	printf("\n\n where is World? \n");
// 	printf("World is at index: %d", ft_lstgetby_content(*lst, "World"));
// 	printf("\n\n where is You? \n");
// 	printf("You is at index: %d", ft_lstgetby_content(*lst, "you"));
// 	printf("\n\n let's del you: \n");
// 	ft_lstdel_here(lst, 9);
// 	ft_lstprint(lst);
// 	printf("\n\n now, let's add someone else:\n");
// 	ft_lstadd_here(lst, ft_lstnew("Joe"), 9);
// 	ft_lstprint(lst);
// 	printf("\n\n let's free all nodes:\n");
// 	ft_lstfree_nodes(lst);
// 	ft_lstprint(lst);
// 	printf("\n\n do we still the list's adress? \n");
// 	ft_lstadd_back(lst, ft_lstnew("Yes"));
// 	ft_lstadd_back(lst, ft_lstnew("we"));
// 	ft_lstadd_back(lst, ft_lstnew("do!"));
// 	ft_lstprint(lst);
// 	printf("\n\nfinally, we'll free all nodes and the list itself:\n");
// 	ft_lstfree(lst);
// 	lst = NULL;
// 	ft_lstprint(lst);
// }
//
// static void	list_init(t_node **lst)
// {
// 	ft_lstadd_back(lst, ft_lstnew("Hello"));
// 	ft_lstadd_back(lst, ft_lstnew("World"));
// 	ft_lstadd_back(lst, ft_lstnew("How"));
// 	ft_lstadd_back(lst, ft_lstnew("are"));
// 	ft_lstadd_back(lst, ft_lstnew("you?"));
// 	ft_lstadd_back(lst, ft_lstnew("I"));
// 	ft_lstadd_back(lst, ft_lstnew("am"));
// 	ft_lstadd_back(lst, ft_lstnew("fine"));
// 	ft_lstadd_back(lst, ft_lstnew("and"));
// 	ft_lstadd_back(lst, ft_lstnew("you"));
// 	ft_lstadd_back(lst, ft_lstnew("?"));
// }
