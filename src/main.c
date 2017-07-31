#include "hls.h"

void				lengths_solo(long int *lengths, char **tabs, char *options)
{
	stats			statf;
	int				i;

	i = 0;
	ft_bzero(lengths, sizeof(long int) * MAX_LENS);
	while (tabs[++i])
		if (!lstat(tabs[i], &statf))
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

int					check_dirs(char **tab, int i, char *opt, int argc)
{
	stats			statf;
	DIR				*dir_id;

	if (i == argc)
		ft_putchar('\n');
	if (!(dir_id = opendir(tab[i])))
	{
		if (lstat(tab[i], &statf))
			ft_putstr_cat(NEXIST_1, tab[i], NEXIST_2, 1);
		else if (statf.st_mode)
			print_solo_file(tab, i, opt, statf);
		else
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

	i = 0;
	opt = NULL;
	opt = get_opt(ac, av);
	while (++i < ac)
		if (av[i][0] != '-' && check_dirs(av, i, opt, ac))
			list_dir(opt, av[i], NULL, 0);
	if (opt)
		free(opt);
	return 0;
}
