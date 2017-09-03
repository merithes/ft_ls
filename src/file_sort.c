/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 21:38:06 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 22:41:55 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

static long int		get_filtime(char *opt, char *file)
{
	t_stats			statf;

	if (lstat(file, &statf))
		return (0);
	if (opt && opt[C])
		return (statf.st_ctime);
	else if (opt && opt[U])
		return (statf.st_atime);
	return (statf.st_mtime);
}

static void			swapper_alpha_time(char *opt, char **tab, int qty)
{
	int				*alpha;
	char			*tmp[qty + 1];
	int				i;
	int				temp_o[3];

	temp_o[0] = opt[T];
	temp_o[1] = opt[U];
	temp_o[2] = opt[C];
	opt[T] = 0;
	opt[U] = 0;
	opt[C] = 0;
	if (!(alpha = sort_solo(opt, tab, qty)))
		return ;
	i = -1;
	while (++i < qty)
		tmp[i] = tab[alpha[i]];
	i = -1;
	while (++i < qty)
		tab[i] = tmp[i];
	opt[T] = temp_o[0];
	opt[U] = temp_o[1];
	opt[C] = temp_o[2];
	free(alpha);
}

static int			*sort_time(char *opt, char **tab, int qty)
{
	int				i[4];
	int				*outp;
	long int		times[qty];

	swapper_alpha_time(opt, tab, qty);
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
		times[i[0]] = get_filtime(opt, tab[i[0]]);
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

int					*sort_solo(char *opt, char **tab, int qty)
{
	int				*outp;
	int				i[3];

	if (!(i[0] = -1) || (opt && opt[F]))
		return (not_sorted(qty));
	if ((opt && opt[T]) || (opt && (opt[C] || opt[U]) && !opt[L]))
		return (sort_time(opt, tab, qty));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[2] = 0;
		while (++i[1] < qty)
			if (opt && opt[REV])
				i[2] += (ft_strcmp(tab[i[0]], tab[i[1]]) < 0) ?
					1 : 0;
			else
				i[2] += (ft_strcmp(tab[i[0]], tab[i[1]]) > 0) ?
					1 : 0;
		outp[i[2]] = i[0];
	}
	return (outp);
}
