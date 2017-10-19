/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 20:52:41 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/19 18:50:43 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void				order_list(char **tab, int qty, int order[], char *opt)
{
	int				i[4];
	int				tmp;

	i[2] = (opt && opt[REV]) ? -1 : 1;
	i[0] = -1;
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[3] = 0;
		while (++i[1] < qty)
			if ((tmp = ft_strcmp(tab[i[0]],
							tab[i[1]])) * i[2] > 0)
				i[3]++;
			else if (tmp == 0 && i[0] != i[1])
				i[3] += (i[0] * i[2] > i[1] * i[2]) ? 1 : 0;
		order[i[3]] = i[0];
	}
}

struct timespec		get_param_time(char *opt, char *nam)
{
	struct stat		statf;

	if (lstat(nam, &statf))
	{
		statf.st_mtimespec.tv_sec = 0;
		statf.st_mtimespec.tv_nsec = 0;
		return (statf.st_mtimespec);
	}
	if (opt && opt[U])
		return (statf.st_atimespec);
	if (opt && opt[C])
		return (statf.st_ctimespec);
	return (statf.st_mtimespec);
}

void				order_list_t(char **tab, int qty, int order[], char *opt)
{
	struct timespec	times[qty];
	int				i[4];

	i[2] = (opt && opt[REV]) ? -1 : 1;
	i[0] = -1;
	while (++i[0] < qty)
		times[i[0]] = get_param_time(opt, tab[i[0]]);
	i[0] = -1;
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[3] = 0;
		while (++i[1] < qty)
			if ((times[i[0]].tv_sec * i[2] < times[i[1]].tv_sec * i[2] ||
				(times[i[0]].tv_sec == times[i[1]].tv_sec &&
					times[i[0]].tv_nsec * i[2] < times[i[1]].tv_nsec * i[2])) ||
					((times[i[0]].tv_sec == times[i[1]].tv_sec &&
					times[i[0]].tv_nsec == times[i[1]].tv_nsec) &&
					i[1] * i[2] > i[0] * i[2]))
				i[3]++;
		order[i[3]] = i[0];
	}
}

void				sort_params(char **tab, int qty, char *opt)
{
	int				order[qty];
	char			*tmp[qty];
	int				i;

	if (opt && (opt[F] || opt[U]))
		return ;
	i = -1;
	order_list(++tab, --qty, order, opt);
	while (++i < qty)
		tmp[i] = tab[order[i]];
	i = -1;
	while (++i < qty)
		tab[i] = tmp[i];
	if (opt && opt[T])
	{
		ft_bzero(order, qty);
		order_list_t(tab, qty, order, opt);
		i = -1;
		while (++i < qty)
			tmp[i] = tab[order[i]];
		i = -1;
		while (++i < qty)
			tab[i] = tmp[i];
	}
}
