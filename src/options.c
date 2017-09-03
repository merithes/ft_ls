/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:08:17 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/29 19:20:00 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void			register_opt(char *outp, char a)
{
	outp[A] = (a == 'a') ? outp[A] + 1 : outp[A];
	outp[S] = (a == 's') ? outp[S] + 1 : outp[S];
	outp[L] = (a == 'l') ? outp[L] + 1 : outp[L];
	outp[REC] = (a == 'R') ? outp[REC] + 1 : outp[REC];
	outp[REV] = (a == 'r') ? outp[REV] + 1 : outp[REV];
	outp[T] = (a == 't') ? outp[T] + 1 : outp[T];
	outp[C] = (a == 'c') ? outp[C] + 1 : outp[C];
	outp[F] = (a == 'f') ? outp[F] + 1 : outp[F];
	outp[U] = (a == 'u') ? outp[U] + 1 : outp[U];
	outp[O] = (a == 'o') ? outp[O] + 1 : outp[O];
	outp[G] = (a == 'g') ? outp[G] + 1 : outp[G];
	if (a == 'f' || a == 't')
		(a == 'f') ? (outp[T] = 0)
			: (outp[F] = 0);
}

char			*opt_filter(char *av, char *inp)
{
	char		a;
	char		*outp;
	int			i;

	if (!(i = 0) &&
		!(outp = inp))
		if (!(outp = ft_strnew(MAX_OPT)))
			return (NULL);
	while ((a = av[++i]) != 0)
	{
		if (a != 'l' && a != 'R' && a != 'a' && a != 'r' && a != 't' && a != 'c'
			&& a != 's' && a != 'f' && a != 'u' && a != 'o' && a != 'g')
		{
			free(outp);
			ft_putstr("ft_ls: invalid option -- '");
			ft_putchar(a);
			ft_putstr("'\nTry 'ls --help' for more information.\n");
			exit(0);
		}
		register_opt(outp, a);
	}
	return (outp);
}

char			*get_opt(int ac, char **av)
{
	int			iav;
	int			witness;
	char		*outp;
	t_stats		statf;

	iav = 0;
	witness = 0;
	outp = NULL;
	while (iav < ac && av[iav])
	{
		if (av[iav][0] != '-')
			iav++;
		else if (!lstat(av[iav], &statf))
			iav++;
		else if (!(outp = opt_filter(av[iav++], outp)) || ++witness == 0)
			return (NULL);
	}
	if (witness == 0)
		return (NULL);
	return (outp);
}
