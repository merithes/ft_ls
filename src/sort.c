#include "hls.h"

long int			get_filtime(char *opt, char *parent, char *file)
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
	//printf("%s\t%s\t%s\t\n", file, ctime(&statf.st_ctim.tv_sec), ctime(&statf.st_mtim.tv_sec));
	if (opt && opt[C])
		return (statf.st_ctim.tv_sec);
	else if (opt && opt[U])
		return (statf.st_atim.tv_sec);
	return (statf.st_mtim.tv_sec);
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

int					*not_sorted(int qty)
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

	i[0] = -1;
	if (opt && opt[F])
		return (not_sorted(qty));
	if ((opt && opt[T]) || (opt && (opt[C] || opt[U]) && !opt[L]))
		return (sort_time(opt, tab, qty, nam));
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while(++i[0] < qty)
	{
		i[1] = 0;
		i[2] = 0;
		while (i[1] < qty)
		{
			if (opt && opt[REV])
				i[2] += (ft_strcmp(tab[i[0]]->d_name, tab[i[1]]->d_name) < 0) ? 1 : 0;
			else
				i[2] += (ft_strcmp(tab[i[0]]->d_name, tab[i[1]]->d_name) > 0) ? 1 : 0;
			i[1]++;
		}
		outp[i[2]] = i[0];
	}
	return (outp);
}
