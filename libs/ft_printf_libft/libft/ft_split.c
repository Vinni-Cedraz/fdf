/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:49:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/18 03:02:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned int	t_uint;

static char				*_substr(char const *s, t_uint start, size_t len);
static void				init_tool(t_split *tool, char const *s, char c);
static void				delimit_start_and_end_of_word(t_split *tool);

t_split	*ft_split(char const *s, char c)
{
	size_t	i;
	t_split	*tool;

	i = -1;
	if (!s)
		return (NULL);
	tool = malloc(sizeof(t_split));
	init_tool(tool, s, c);
	while (++i < tool->number_of_words)
	{
		delimit_start_and_end_of_word(tool);
		tool->str_arr[i] = _substr(tool->start, 0, tool->end - tool->start);
	}
	return (tool);
}

static inline void	init_tool(t_split *tool, char const *s, char c)
{
	tool->whtspce = c;
	tool->number_of_words = ft_word_counter(s, c);
	tool->start = (char *)s;
	tool->end = tool->start;
	tool->str_arr = ft_calloc(tool->number_of_words + 1, sizeof(char *));
}

static char	*_substr(char const *s, t_uint start, size_t len)
{
	char	*substr;
	t_uint	s_len;

	s_len = (t_uint)ft_strlen(s);
	if (start > s_len)
		return (malloc(0));
	else if (len > s_len - start)
	{
		substr = malloc((s_len - start + 1) * sizeof(char));
		ft_memcpy(substr, s + start, s_len - start);
		substr[s_len - start] = '\0';
		return (substr);
	}
	else
	{
		substr = malloc((len + 1) * sizeof(char));
		ft_memcpy(substr, s + start, len);
		substr[len] = '\0';
		return (substr);
	}
}

static inline void	delimit_start_and_end_of_word(t_split *tool)
{
	int	wordlen;

	while (*tool->end == tool->whtspce)
	{
		tool->end++;
		if (*tool->end != tool->whtspce)
			tool->start = tool->end;
	}
	wordlen = ft_strlen(tool->start);
	tool->end = ft_memchr(tool->start, tool->whtspce, wordlen);
	if (!tool->end)
		tool->end = tool->end + wordlen;
}

//
// // lame version for libfTester
// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	t_split	*tool;
// 	char	**res;
//
// 	i = -1;
// 	if (!s)
// 		return (NULL);
// 	tool = malloc(sizeof(t_split));
// 	init_tool(tool, s, c);
// 	while (++i < tool->number_of_words)
// 	{
// 		delimit_start_and_end_of_word(tool);
// 		tool->str_arr[i] = _substr(tool->start, 0, tool->end - tool->start);
// 	}
// 	res = copy_str_arr(tool);
// 	ft_free_arr((char **)tool->str_arr, (void **)tool->str_arr);
// 	free(tool);
// 	return (res);
// }
