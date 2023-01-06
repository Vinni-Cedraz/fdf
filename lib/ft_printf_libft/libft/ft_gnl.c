/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/05 23:49:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*l_make(char *line, char *append, int copy_n_bytes,
						int size);
static char			*read_fd(int fd, t_module old, t_module *mod_new,
						int l_size);

char	*ft_gnl(int fd)
{
	static t_module	mod_list[1024];
	t_module		mod;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	mod = mod_list[fd];
	while (mod.l_end < mod.read && mod.buf[mod.l_end] != '\n')
		mod.l_end++;
	mod.l_sz = mod.l_end - mod.l_bgn;
	if (mod.l_end < mod.read)
	{
		mod.l_sz++;
		line = l_make(0, mod.buf + mod.l_bgn, mod.l_sz, mod.l_sz);
		mod.l_bgn= mod.l_end + 1;
		mod.l_end = mod.l_bgn;
		mod_list[fd] = mod;
	}
	else
	{
		line = read_fd(fd, mod, mod_list + fd, mod.l_sz);
		destroy_module(&mod);
	}
	return (line);
}

static inline char	*l_make(char *line, char *append, int copy_n_bytes,
		int size)
{
	if (size)
	{
		line = malloc(size + 1);
		if (line)
			line[size] = 0;
		size -= copy_n_bytes;
	}
	if (line)
		while (copy_n_bytes--)
			line[size++] = *append++;
	return (line);
}

static char	*read_fd(int fd, t_module old, t_module *mod_new, int l_size)
{
	t_module	tmp;
	char		*line;
	int			total_size;

	total_size = l_size;
	while (1)
	{
		if (create_module(&tmp, fd))
			return (0);
		if (tmp.l_bgn> BUFFER_SIZE)
		{
			total_size += BUFFER_SIZE;
			continue ;
		}
		else
		{
			line = l_make(0, tmp.buf, tmp.l_sz, total_size + tmp.l_sz);
			if (old.buf)
				l_make(line, old.buf + old.l_bgn, old.l_sz, 0);
			*mod_new = tmp;
			return (line);
		}
		if (line)
			l_make(line + total_size, tmp.buf, BUFFER_SIZE, 0);
		destroy_module(&tmp);
	}
}
