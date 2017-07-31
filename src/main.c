#include "hls.h"

void				lengths_solo(long int *lengths, char **tabs, char *options)
{
	stats			statf;
	int				i;

	i = 0;
	ft_bzero(lengths, sizeof(long int) * MAX_LENS);
	while (tabs[++i])
		if (tabs[i][0] != '-' && !lstat(tabs[i], &statf))
			compare_stock(lengths, statf, tabs[i], options);
}

void				print_solo_file(char **tab, int i, char *opt, stats statf)
{
	char			stat_tab[766];
	long int		infos_len[MAX_LENS];

	if (!opt || (opt && !opt[L]))
		ft_putstr_cat(NULL, tab[i], "\t", 0);
	else
	{
		lengths_solo(infos_len, tab, opt);
		ft_putstr_cat(getstat(statf, stat_tab, infos_len), tab[i], NULL, 1);
	}
}

int					chk_d(char **tab, int i, char *opt, int *type)
{
	stats			statf;
	DIR				*dir_id;

	if (!(dir_id = opendir(tab[i])))
	{
		if (lstat(tab[i], &statf))
			(!type[0]) ? ft_putstr_cat(NEXIST_1, tab[i], NEXIST_2, 1) : 1;
		else if (statf.st_mode >= S_IFREG && statf.st_mode < S_IFLNK)
			(type[0] && type[0] != 2 && (type[1] = 2)) ?
				print_solo_file(tab, i, opt, statf) : 1;
		else if (!type[0])
			ft_putstr_cat(NPERMS_1, tab[i], NPERMS_2, 1);
		return (0);
	}
	else
		closedir(dir_id);
	return (1);

}

int					main(int ac, char **av)
{
	char			*opt;
	int				i;
	int				wit[3];
	int				is_inp_a_file;

	ft_bzero(wit, 3 * sizeof(int));
	opt = NULL;
	is_inp_a_file = 0;
	opt = get_opt(ac, av);
	while (!(i = 0) && wit[0] <= 1)
	{
		while (av[++i])
			(av[i][0] != '-') ? wit[2] += (chk_d(av, i, opt, wit) == 0) 1 : 180; 
		(wit[0]++ && (wit[2] % 180)) ? ft_putstr("\n") : 1;
	}
	while (++i < ac)
	{
		printf("%d\t%d\t%d\n", wit[0], wit[1], wit[2]);
		if (av[i][0] != '-' && chk_d(av, i, opt, wit))
			list_dir(opt, av[i], NULL, 0 + wit[1] + wit[2]);
		(wit[2] / 2) ? ft_putchar('\n') : 1;
	}
	opt ? free(opt) : ac++;
	return 0;
}
