/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 20:52:41 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 22:59:57 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void				order_list(char **tab, int qty, int order[], char *opt)
{
	int				i[4];
	int				tmp;

	i[2] = (opt && opt[REV]) ? -1 : 1;
	i[0] = -1;
	while (++i[0] < qty)
	{
		i[1] = -1;
		i[3] = 0;
		while (++i[1] < qty)
			if ((tmp = ft_strcmp(tab[i[0]],
				tab[i[1]])) * i[2] > 0)
				i[3]++;
			else if (tmp == 0 && i[0] != i[1])
				i[3] += (i[0] * i[2] > i[1] * i[2]) ? 1 : 0;
		order[i[3]] = i[0];
	}
}

void				sort_params(char **tab, int qty, char *opt)
{
	int				order[qty];
	char			**tmp;
	int				i;

	if (opt && (opt[F] || opt[U]))
		return ;
	i = -1;
	tab++;
	qty--;
	tmp = malloc(sizeof(char **) * qty);
	order_list(tab, qty, order, opt);
	while (++i < qty)
		tmp[i] = tab[order[i]];
	i = -1;
	while (++i < qty)
		tab[i] = tmp[i];
	free(tmp);
}
