#include "hls.h"

int					check_dirs(char *tab, int do_i_speak)
{
	stats			statf;
	DIR				*dir_id;

	if (!(dir_id = opendir(tab)))
	{
		if (lstat(tab, &statf))
		{
			if (do_i_speak)
				ft_putstr_cat(NEXIST_1, tab, NEXIST_2, 1);
		}
		else
			if (do_i_speak)
				ft_putstr_cat(NPERMS_1, tab, NPERMS_2, 1);
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
		if (av[i][0] != '-' && check_dirs(av[i], 1))
			list_dir(opt, av[i], NULL, 0);
	if (opt)
		free(opt);
	return 0;
}
