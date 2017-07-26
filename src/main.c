#include "hls.h"

void				check_ds(int cnt, char **tab)
{
	int				i;
	DIR				*dir_id;

	i = 0;
	while (++i < cnt)
	{
		if (tab[i][0] != '-')
		{
			if (!(dir_id = opendir(tab[i])))
			{
				ft_putstr("ft_ls: cannot access '");
				ft_putstr(tab[i]);
				ft_putstr("': No such file or directory.\n");
				exit(0);
			}
			else
				closedir(dir_id);
		}
	}
}

int					main(int ac, char **av)
{
	char			*opt;
	int				i;

	i = 0;
	opt = get_opt(ac, av);
	check_ds(ac, av);
	while (++i < ac)
		if (av[i][0] != '-')
			list_dir(opt, av[i]);
	return 0;
}
