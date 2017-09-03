/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:22:20 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 18:40:24 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

struct dirent	**f_ilter(char *inp)
{
	struct dirent	**tab_out;

	if (!inp || inp[0] == '-')
		return (NULL);
	if (!(tab_out = malloc(sizeof(struct dirent *) * 6)))
	{
		ft_putstr("Lacking memory to properly process\n");
		return (NULL);
	}
	ft_bzero(tab_out, sizeof(struct dirent *) * 6);
	return (tab_out);
}

char			*mknam(char *s1, char *s2)
{
	char		*outp;
	int			len;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(outp = ft_strnew(len)))
		return (NULL);
	ft_bzero(outp, len);
	if (ft_strcmp(s1, "/"))
		ft_strcpy(outp, s1);
	ft_strcat(outp, "/");
	ft_strcat(outp, s2);
	return (outp);
}

int				*printd(struct dirent **file, int qty, char *opt, char *nam)
{
	int			i;
	int			*order;
	char		*tmp;
	t_stats		statf;

	order = sort(opt, file, qty, nam);
	tmp = NULL;
	i = -1;
	while (++i < qty)
		if (file[order[i]]->d_name[0] != '.' || (opt && (opt[A] || opt[F])))
		{
			if (opt && opt[S] &&
				!lstat((tmp = mknam(nam, file[order[i]]->d_name)), &statf))
			{
				ft_putnbr(statf.st_blocks / 2);
				ft_putchar('\t');
				free(tmp);
			}
			pcat(NULL, file[order[i]]->d_name, NULL, 1);
		}
	return (order);
}
