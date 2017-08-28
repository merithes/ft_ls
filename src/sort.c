/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:38:06 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/28 18:14:04 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

long int			get_filtime(char *opt, char *parent, char *file)
{
	char			outp[3000];
	t_stats			statf;

	ft_bzero(outp, 3000);
	if (parent && ft_strcmp(parent, "/"))
		ft_strcpy(outp, parent);
	ft_strcat(outp, "/");
	ft_strcat(outp, file);
	if (lstat(outp, &statf))
		return (0);
	if (opt && opt[C])
		return (statf.st_ctime);
	else if (opt && opt[U])
		return (statf.st_atime);
	return (statf.st_mtime);
}

int					*sort_time(char *opt, t_dirs **tab, int qty, char *nam)
{
	int				i[4];
	int				*outp;
	long int		times[qty];

	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
		times[i[0]] = get_filtime(opt, nam, tab[i[0]]->d_name);
	i[0] = -1;
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[3] = 0;
		while (++i[1] < qty)
			if (times[i[0]] * i[2] < times[i[1]] * i[2] ||
				(times[i[0]] == times[i[1]] && i[0] * i[2] > i[1] * i[2]))
				i[3]++;
		outp[i[3]] = i[0];
	}
	return (outp);
}

static int			*not_sorted(int qty)
{
	int				*outp;
	int				i;

	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i = -1;
	while (++i < qty)
		outp[i] = i;
	return (outp);
}

int					*sort(char *opt, struct dirent **tab, int qty, char *nam)
{
	int				*outp;
	int				i[3];

	if (!(i[0] = -1) || (opt && opt[F]))
		return (not_sorted(qty));
	if ((opt && opt[T]) || (opt && (opt[C] || opt[U]) && !opt[L]))
		return (sort_time(opt, tab, qty, nam));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[2] = 0;
		while (++i[1] < qty)
			if (opt && opt[REV])
				i[2] += (ft_strcmp(tab[i[0]]->d_name, tab[i[1]]->d_name) < 0) ?
					1 : 0;
			else
				i[2] += (ft_strcmp(tab[i[0]]->d_name, tab[i[1]]->d_name) > 0) ?
					1 : 0;
		outp[i[2]] = i[0];
	}
	return (outp);
}
