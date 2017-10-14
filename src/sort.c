/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:38:06 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/13 20:07:45 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

struct timespec		get_filtime(char *opt, char *parent, char *file)
{
	char			outp[MAXPATHLEN];
	struct stat		statf;

	ft_bzero(outp, MAXPATHLEN);
	if (parent && ft_strcmp(parent, "/"))
		ft_strcpy(outp, parent);
	ft_strcat(outp, "/");
	ft_strcat(outp, file);
	if (lstat(outp, &statf))
	{
		statf.st_mtim.tv_sec = 0;
		statf.st_mtim.tv_nsec = 0;
		return (statf.st_mtim);
	}
	if (opt && opt[C])
		return (statf.st_ctim);
	else if (opt && opt[U])
		return (statf.st_atim);
	return (statf.st_mtim);
}

void				swapper_alpha_time(char *opt,
						t_dirs **tab, int qty, char *nam)
{
	int				*alpha;
	t_dirs			*tmp[qty + 1];
	int				i;
	int				temp_o[4];

	temp_o[0] = opt[T];
	temp_o[1] = opt[U];
	temp_o[2] = opt[C];
	temp_o[3] = opt[REV];
	opt[T] = 0;
	opt[U] = 0;
	opt[C] = 0;
	opt[REV] = 0;
	(!(alpha = sort(opt, tab, qty, nam))) ? exit(-151) : 1;
	i = -1;
	while (++i < qty)
		tmp[i] = tab[alpha[i]];
	i = -1;
	while (++i < qty)
		tab[i] = tmp[i];
	opt[T] = temp_o[0];
	opt[U] = temp_o[1];
	opt[C] = temp_o[2];
	opt[REV] = temp_o[3];
	free(alpha);
}

int					*sort_time(char *opt, t_dirs **tab, int qty, char *nam)
{
	int				i[4];
	int				*outp;
	struct timespec	times[qty];

	swapper_alpha_time(opt, tab, qty, nam);
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
		times[i[0]] = get_filtime(opt, nam, tab[i[0]]->d_name);
	i[0] = -1;
	while (++i[0] < qty && !(i[3] = 0))
	{
		i[1] = -1;
		while (++i[1] < qty)
			if ((times[i[0]].tv_sec * i[2] < times[i[1]].tv_sec * i[2] ||
				(times[i[0]].tv_sec == times[i[1]].tv_sec &&
				times[i[0]].tv_nsec * i[2] < times[i[1]].tv_nsec * i[2])) ||
					((times[i[0]].tv_sec == times[i[1]].tv_sec &&
					times[i[0]].tv_nsec == times[i[1]].tv_nsec) &&
					 i[1] * i[2] > i[0] * i[2]))
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
