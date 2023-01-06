/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 18:40:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*l_make(char *line, char *append, int copy_n_bytes, int size);
static void		read_file_and_create_module(t_mod *mod, int fd);
static char		*read_fd(int fd, t_mod old, t_mod *mod_new, int l_size);

char	*ft_gnl(int fd)
{
	static t_mod	mod_list[1024];
	t_mod			mod;
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
		mod.l_bgn = mod.l_end + 1;
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

static char	*read_fd(int fd, t_mod old, t_mod *mod_new, int l_size)
{
	t_mod	tmp;
	char	*line;
	int		total_size;

	total_size = l_size;
	while (1)
	{
		read_file_and_create_module(&tmp, fd);
		if (tmp.read_failed || tmp.malloc_failed)
			return (0);
		if (tmp.l_bgn > BUFFER_SIZE)
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
	}
}

static void	read_file_and_create_module(t_mod *mod, int fd)
{
	mod->l_bgn = 0;
	mod->buf = malloc(BUFFER_SIZE);
	if (!mod->buf)
	{
		mod->malloc_failed = 1;
		return ;
	}
	mod->read = read(fd, mod->buf, BUFFER_SIZE);
	if (mod->read < 1)
		destroy_module(mod);
	if (mod->read < 0)
	{
		mod->read_failed = 1;
		return ;
	}
	while (mod->l_bgn < mod->read && mod->buf[mod->l_bgn] != '\n')
		mod->l_bgn++;
	if (mod->l_bgn < mod->read)
		mod->l_sz = mod->l_bgn + 1;
	else
		mod->l_sz = mod->l_bgn;
	mod->l_bgn++;
	mod->l_end = mod->l_bgn;
}
