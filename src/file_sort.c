#include "hls.h"

long int			get_filtime_solo(char *opt, char *file)
{
	stats			statf;

	if (lstat(file, &statf))
		return (0);
	if (opt && opt[C])
		return (statf.st_ctim.tv_sec);
	if (opt && opt[U])
		return (statf.st_atim.tv_sec);
	return (statf.st_mtim.tv_sec);
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

void				re_filter(char **tab)
{
	char			*tmp;
	int				i;

	tmp = NULL;
	i = -1;
	while (tab[++i])
		if ((tmp = ft_strrchr(tab[i], '/')) != NULL)
			tab[i] = tmp + 1;
}

int					*sort_solo(char *opt, char **tab, int qty)
{
	int				*outp;
	int				i;
	int				ic;
	int				cnt;

	i = -1;
	if ((opt && opt[T]) || (opt && (opt[C] || opt[U]) && !opt[L]))
		return (sort_time_solo(opt, tab, qty));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	re_filter(tab);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while(++i < qty && !(ic = 0))
	{
		cnt = 0;
		while (ic < qty)
		{
			if (opt && opt[REV])
				cnt += (ft_strcmp(tab[i], tab[ic]) < 0) ? 1 : 0;
			else
				cnt += (ft_strcmp(tab[i], tab[ic]) > 0) ? 1 : 0;
			ic++;
		}
		outp[cnt] = i;
	}
	return (outp);
}
