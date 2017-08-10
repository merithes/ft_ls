#include "hls.h"

int					*sort_time(char *opt, dirs **tab, int qty, char *nam)
{
	int				i[4];
	int				*outp;
	char			*tmp;
	stats			statf[2];

	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
	{
		lstat(tmp = mknam(nam, tab[i[0]]->d_name), &statf[0]);
		(tmp) ? (free(tmp), 1) : 1;
		i[1] = -1;
		i[3] = 0;
		while (++i[1] < qty && !lstat(tmp = mknam(nam, tab[i[1]]->d_name), &statf[1]))
			if ((statf[0].st_mtime * i[2] < statf[1].st_mtime * i[2] ||
				(statf[0].st_mtime == statf[1].st_mtime &&
					i[0] * i[2] > i[1] * i[2])) && (free(tmp), 1))
					i[3] += 1;
		outp[i[3]] = i[0];
	}
	return (outp);
}

int					*sort(char *opt, struct dirent **tab, int qty, char *nam)
{
	int				*outp;
	int				i;
	int				ic;
	int				cnt;

	i = -1;
	if (opt && opt[T])
		return (sort_time(opt, tab, qty, nam));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while(++i < qty)
	{
		ic = 0;
		cnt = 0;
		while (ic < qty)
		{
			if (opt && opt[REV])
				cnt += (ft_strcmp(tab[i]->d_name, tab[ic]->d_name) < 0) ? 1 : 0;
			else
				cnt += (ft_strcmp(tab[i]->d_name, tab[ic]->d_name) > 0) ? 1 : 0;
			ic++;
		}
		outp[cnt] = i;
	}
	return (outp);
}
