/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:04:58 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/26 21:10:01 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

int				*printd_l(char *nam, struct dirent **file, int qty, char *opt)
{
	int				i;
	int				*order;
	struct stat		statf;
	char			*str_stat[3];
	long int		*infos_len;

	if (!(str_stat[0] = malloc(STRSIZE * sizeof(char))))
		return (NULL);
	i = -1;
	order = sort(opt, file, qty, nam);
	infos_len = len_infos(nam, file, qty, opt);
	put_total(infos_len[BLK_CNT]);
	while (++i < qty)
		if ((file[order[i]]->d_name[0] != '.' || (opt && (opt[A] || opt[F])))
			&& !lstat(str_stat[1] = mknam(nam, file[order[i]]->d_name), &statf))
		{
			ft_putstr_cat((getstat(statf, str_stat[0], infos_len, opt))
				, file[order[i]]->d_name
					, str_stat[2] = link_symlink(str_stat[1]), 1);
			free(str_stat[1]);
			(str_stat[2] != NULL) ? free(str_stat[2]) : 1;
		}
	free(infos_len);
	free(str_stat[0]);
	ft_putchar('\n');
	return (order);
}

void			list_tool(char *opt, struct dirent **content,
				char *nam, int qty)
{
	int				*ord;
	char			*tmp;
	int				i;
	DIR				*direc;

	if ((i = -1) && opt && opt[L])
		ord = printd_l(nam, content, qty, opt);
	else
		ord = printd(content, qty, opt, nam);
	if (!ord)
		return ;
	while (++i < qty && (opt && opt[REC]))
		if (content[ord[i]]->d_type == 4 && (((opt && opt[REC]) &&
				(ft_strcmp(content[ord[i]]->d_name, ".") != 0 &&
					ft_strcmp(content[ord[i]]->d_name, "..") != 0)) &&
						((content[ord[i]]->d_name[0] != '.') ||
							(opt && (opt[A] || opt[F])))))
		{
			if ((direc = opendir(tmp = mknam(nam, content[ord[i]]->d_name))))
				list_dir(opt, tmp, direc, 1);
			else
				ft_putstr_cat("ft_ls: ", content[ord[i]]->d_name, ": Permission denied", 1);
			free(tmp);
		}
	free(ord);
}

struct dirent	**realloc_dirent(struct dirent **inp, int size)
{
	int				i;
	struct dirent	**outp;

	i = 0;
	if (!(outp = malloc(sizeof(struct dirent *) * (size + 6))))
		return (NULL);
	ft_bzero(outp, sizeof(struct dirent *) * size + 6);
	while ((outp[i] = inp[i]) && i <= size)
	{
		i++;
	}
	(inp) ? free(inp) : 1;
	return (outp);
}

struct dirent	*mem_make_dirent(struct dirent *inp)
{
	struct dirent *outp;

	if (inp)
	{
		if (!(outp = malloc(sizeof(struct dirent))))
			return (NULL);
		ft_memcpy(outp, inp, sizeof(struct dirent));
	}
	else
		return (NULL);
	return (outp);
}

void			list_dir(char *opt, char *av, DIR *inp, int context)
{
	int				i;
	DIR				*dir_id;
	struct dirent	**readtab;

	i = -1;
	if (!(readtab = f_ilter(av)))
		return ;
	if ((opt && opt[REC]) || context / 2)
		ft_putstr_cat(av, ":", NULL, 1);
	dir_id = (context % 2) ? inp : opendir(av);
	while (++i >= 0)
	{
		if (!(readtab[i] = mem_make_dirent(readdir(dir_id))))
			break ;
		if ((i + 1) % 5 == 0 && i != 0)
			readtab = realloc_dirent(readtab, i);
	}
	list_tool(opt, readtab, av, i);
	i = 0;
	while (readtab[i])
		free(readtab[i++]);
	free(readtab);
	closedir(dir_id);
}
