/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 17:09:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdio.h>

static char		*l_make(char *line, char *append, int copy_n_bytes, int size);
static void		read_fp_create_module(t_mod *mod, FILE *fp);
static char		*read_fp(FILE *fp, t_mod old, t_mod *mod_new, int l_size);
static void		destroy_module(t_mod *mod);

char	*ft_special_gnl(FILE *fp)
{
	static t_mod	mod_list[1];
	t_mod			mod;
	char			*line;

	mod = mod_list[0];
	while (mod.l_end < mod.read && mod.buf[mod.l_end] != '\n')
		mod.l_end++;
	mod.l_sz = mod.l_end - mod.l_bgn;
	if (mod.l_end < mod.read)
	{
		mod.l_sz++;
		line = l_make(0, mod.buf + mod.l_bgn, mod.l_sz, mod.l_sz);
		mod.l_bgn = mod.l_end + 1;
		mod.l_end = mod.l_bgn;
		mod_list[0] = mod;
	}
	else
	{
		line = read_fp(fp, mod, mod_list, mod.l_sz);
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

static char	*read_fp(FILE *fp, t_mod old, t_mod *mod_new, int l_size)
{
	t_mod	tmp;
	char	*line;
	int		total_size;

	total_size = l_size;
	while (1)
	{
		read_fp_create_module(&tmp, fp);
		if (tmp.read_failed)
			return (0);
		if (tmp.l_bgn > FIXED_BUFSZ)
		{
			total_size += FIXED_BUFSZ;
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

static void	read_fp_create_module(t_mod *mod, FILE *fp)
{
	mod->l_bgn = 0;
	mod->buf = malloc(FIXED_BUFSZ);
	mod->read = fread(mod->buf, 1, FIXED_BUFSZ, fp);
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

static void	destroy_module(t_mod *mod)
{
	if (mod->buf)
		free(mod->buf);
	mod->buf = 0;
}
