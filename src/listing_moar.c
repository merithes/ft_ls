/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_moar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 18:40:39 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 20:13:30 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void			lengths_solo(long int *lengths, char **tabs, char *options)
{
	t_stats		statf;
	int			i;

	i = -1;
	ft_bzero(lengths, sizeof(long int) * MAX_LENS);
	while (tabs[++i])
		if (!lstat(tabs[i], &statf))
			compare_stock(lengths, statf, tabs[i], options);
	lengths[SIZ_LEN] = ft_intlen(lengths[SIZ_TMP]);
	lengths[LNK_LEN] = ft_intlen(lengths[LNK_TMP]);
	lengths[BLK_LEN] = ft_intlen(lengths[BLK_TMP]);
}

void			append_major_minor(t_stats statf, t_lsi *lengths, char *str)
{
	int			i[2];
	int			len;
	char		*tmp;

	ft_bzero(i, sizeof(int) * 2);
	tmp = ft_litoa((statf.st_rdev >> 24) & 0xFF);
	len = ft_strlen(tmp);
	while (++i[0] + len <= lengths[MAJ_LEN])
		ft_strncat(str, " ", 1);
	ft_strcat(str, tmp);
	free(tmp);
	tmp = ft_litoa(statf.st_rdev & 0xFF);
	len = ft_strlen(tmp);
	ft_strncat(str, ", ", 2);
	while (++i[1] + len <= lengths[MIN_LEN])
		ft_strncat(str, " ", 1);
	ft_strcat(str, tmp);
	ft_strncat(str, " ", 1);
	free(tmp);
}
