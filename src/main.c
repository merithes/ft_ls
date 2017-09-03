/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:10:38 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/29 21:21:52 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void				print_solo_file(char *opt, char *path, char *stat_tab,
						long int *infos_len)
{
	t_stats			statf;

	if (lstat(path, &statf))
		return ;
	if (!opt || (opt && !opt[L]))
		pcat(NULL, path, "\n", 0);
	else
		pcat(getstat(statf, stat_tab, infos_len, opt), path, NULL, 1);
}

void				prnt_files(char **tab, char *opt, int to_line)
{
	int				*order;
	char			stat_tab[STRSIZE];
	long int		infos_len[MAX_LENS];
	int				i[2];

	ft_bzero(i, sizeof(int) * 2);
	order = NULL;
	if (!tab)
		return ;
	while (tab[i[0]] != NULL)
		i[0]++;
	order = sort_solo(opt, tab, i[0]);
	if (opt && opt[L])
		lengths_solo(infos_len, tab, opt);
	while (i[1] < i[0])
		print_solo_file(opt, tab[order[i[1]++]], stat_tab, infos_len);
	if (to_line)
		ft_putchar('\n');
	(order) ? free(order) : 1;
}

void				append_filename(char **tab, char *name)
{
	int				i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	tab[i] = name;
}

int					chk_d(char **tab, int *data, char **file_list)
{
	t_stats			statf;
	DIR				*dir_id;

	if (!(dir_id = opendir(tab[data[5]])))
	{
		if (tab[data[5]][0] == '-' && lstat(tab[data[5]], &statf))
			return (0);
		else if (lstat(tab[data[5]], &statf) && ++data[3] && ++data[6])
			(!data[0]) ? pcat(NEXIST_1, tab[data[5]], NEXIST_2, 1) : 1;
		else if (statf.st_mode >= S_IFREG &&
			statf.st_mode < S_IFLNK && ++data[3] && ++data[8])
		{
			if (data[0] && data[0] != 2 && (data[1] = 2))
				append_filename(file_list, tab[data[5]]);
		}
		else if (!data[0] && ++data[3] && ++data[6])
			pcat(NPERMS_1, tab[data[5]], NPERMS_2, 1);
		return (0);
	}
	else
		closedir(dir_id);
	data[7]++;
	return (1);
}

int					main(int ac, char **av)
{
	char			*opt;
	char			*tab[ac];
	int				wit[9];

	ft_bzero(wit, 9 * sizeof(int));
	ft_bzero(tab, ac * sizeof(char *));
	opt = get_opt(ac, av);
	sort_params(av, ac, opt);
	while (!(wit[5] = 0) && wit[0] <= 1)
	{
		while (av[++wit[5]])
			wit[2] += (chk_d(av, wit, tab) != 0) ? 1 : 0;
		(wit[0]++ && wit[6]) ? ft_putstr("\n") : 1;
	}
	(wit[8]) ? prnt_files(tab, opt, wit[7]) : 1;
	wit[4] = (wit[3] && wit[2]) ? 2 : 0;
	(!wit[3] && !wit[2]) ? list_dir(opt, ".", NULL, 0) : 1;
	wit[2] = (wit[2] / 2 > 1) ? 2 : 0;
	wit[5] = 0;
	while (++wit[5] < ac)
		if (chk_d(av, wit, tab))
			list_dir(opt, av[wit[5]], NULL, 0 + wit[1] + wit[2] + wit[4]);
	opt ? free(opt) : ac++;
	return (0);
}
