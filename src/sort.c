#include "hls.h"

long int			get_mtime(char *parent, char *file)
{
	char			outp[3000];
	stats			statf;

	ft_bzero(outp, 3000);
	if (parent && ft_strcmp(parent, "/"))
		ft_strcpy(outp, parent);
	ft_strcat(outp, "/");
	ft_strcat(outp, file);
	if (lstat(outp, &statf))
		return (0);
	return (statf.st_mtime);
}

int					*sort_time(char *opt, dirs **tab, int qty, char *nam)
{
	int				i[4];
	int				*outp;
	long int		times[qty];

	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	i[0] = -1;
	i[2] = (opt && opt[REV]) ? -1 : 1;
	while (++i[0] < qty)
		times[i[0]] = get_mtime(nam, tab[i[0]]->d_name);
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
