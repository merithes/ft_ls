/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:37:55 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/23 21:39:36 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

long int			get_filtime_solo(char *opt, char *file)
{
	stats			statf;

	if (lstat(file, &statf))
		return (0);
	if (opt && opt[C])
		return (statf.st_ctime);
	if (opt && opt[U])
		return (statf.st_atime);
	return (statf.st_mtime);
}

int					*sort_time_solo(char *opt, char **tab, int qty)
{
	int				i[4];
	int				*outp;
	long int		times[qty];

	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
		times[i[0]] = get_filtime_solo(opt, tab[i[0]]);
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

	if (!(outp = malloc((qty + 1) * sizeof(int))))
		return (NULL);
	i = -1;
	while (++i < qty)
		outp[i] = i;
	return (outp);
}

int					*sort_solo(char *opt, char **tab, int qty)
{
	int				*outp;
	int				i[3];

	i[0] = -1;
	if (opt && opt[F])
			return (not_sorted(qty));
	if ((opt && opt[T]) || (opt && (opt[C] || opt[U]) && !opt[L]))
		return (sort_time_solo(opt, tab, qty));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while(++i[0] < qty && !(i[1] = 0))
	{
		i[2] = 0;
		while (i[1] < qty)
		{
			if (opt && opt[REV])
				i[2] += (ft_strcmp(tab[i[0]], tab[i[1]]) < 0) ? 1 : 0;
			else
				i[2] += (ft_strcmp(tab[i[0]], tab[i[1]]) > 0) ? 1 : 0;
			i[1]++;
		}
		outp[i[2]] = i[0];
	}
	return (outp);
}
