/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:45 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 20:13:27 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

t_lsi			get_time_append(t_stats statf, char *opt)
{
	if (!opt)
		return (statf.st_mtime);
	if (opt[C])
		return (statf.st_ctime);
	else if (opt[U])
		return (statf.st_atime);
	return (statf.st_mtime);
}

void			append_time(char *str, t_stats statf, char *opt)
{
	char		time_alpha[23];
	time_t		tim;

	tim = get_time_append(statf, opt);
	ft_bzero(time_alpha, sizeof(char) * 23);
	if (tim + SIX_MONTH > time(0) && tim < time(0) + 3600)
		ft_strncat(str, ctime(&tim) + 4, 12);
	else
	{
		strcpy(time_alpha, ctime(&tim) + 4);
		time_alpha[7] = ' ';
		time_alpha[8] = time_alpha[16];
		time_alpha[9] = time_alpha[17];
		time_alpha[10] = time_alpha[18];
		time_alpha[11] = time_alpha[19];
		time_alpha[12] = 0;
		ft_strcat(str, time_alpha);
	}
	ft_strncat(str, " ", 1);
}

void			append_size(char *str, t_stats statf, long int *lengths)
{
	char		*size_alpha;
	size_t		len;

	if (lengths[BLK_CHR] && (S_ISBLK(statf.st_mode) || S_ISCHR(statf.st_mode)))
	{
		append_major_minor(statf, lengths, str);
		return ;
	}
	if (!(size_alpha = ft_litoa(statf.st_size)))
		return ;
	len = ft_strlen(size_alpha);
	while ((long int)++len <= lengths[SIZ_LEN])
		ft_strncat(str, " ", 1);
	ft_strncat(str, size_alpha, len);
	free(size_alpha);
	ft_strncat(str, " ", 1);
}

void			append_blk(t_stats statf, char *str, t_lsi *lengths)
{
	char		*tmp;
	int			i;
	int			slen;

	i = -1;
	slen = 0;
	tmp = ft_itoa(statf.st_blocks);
	(tmp) ? slen = ft_strlen(tmp) : 1;
	while (++i + slen < lengths[BLK_LEN])
		ft_strncat(str, " ", 1);
	ft_strcat(str, tmp);
	(tmp) ? free(tmp) : 1;
	ft_strncat(str, " ", 1);
}

void			append_links(char *str, t_stats statf, t_lsi *lengths)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_litoa(statf.st_nlink);
	i = ft_lintlen(statf.st_nlink);
	while (i++ < lengths[LNK_LEN] + 1)
		ft_strncat(str, " ", 1);
	ft_strncat(str, tmp, i);
	free(tmp);
	ft_strncat(str, " ", 1);
}
