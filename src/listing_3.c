/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:06:09 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 18:48:33 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

char			*getstat(struct stat statf,
					char *str, long int *lengths, char *opt)
{
	ft_bzero(str, STRSIZE);
	(opt && opt[S]) ? append_blk(statf, str, lengths) : 1;
	translate_mod(statf.st_mode, str);
	ft_strncat(str, " ", 1);
	append_links(str, statf, lengths);
	append_uid_gid(str, statf, opt, lengths);
	append_size(str, statf, lengths);
	append_time(str, statf, opt);
	return (str);
}

int				compare_stock(t_lsi *d, t_stats statf, char *name, char *o)
{
	struct passwd		*uid;
	struct group		*gid;

	uid = getpwuid(statf.st_uid);
	gid = getgrgid(statf.st_gid);
	if (d)
	{
		if (statf.st_size > d[0] && (name[0] != '.' || (o && o[A])))
			d[SIZ_TMP] = statf.st_size;
		d[LNK_TMP] = COMPARE((size_t)d[LNK_TMP], statf.st_nlink);
		d[BLK_TMP] = COMPARE(d[BLK_TMP], statf.st_blocks);
		d[BLK_CNT] += (name[0] != '.' || (o && o[A])) ? statf.st_blocks : 0;
		if (S_ISBLK(statf.st_mode) || S_ISCHR(statf.st_mode))
		{
			d[BLK_CHR] = 1;
			d[MAJ_TMP] = (((statf.st_rdev >> 24) & 0xFF) > d[MAJ_TMP]) ?
				((statf.st_rdev >> 24) & 0xFF) : d[MAJ_TMP];
			d[MIN_TMP] = ((statf.st_rdev & 0xFF) > d[MIN_TMP]) ?
				(statf.st_rdev & 0xFF) : d[MIN_TMP];
		}
		if (uid && gid)
		{
			d[UID_LEN] = COMPARE(d[UID_LEN], (long int)ft_strlen(uid->pw_name));
			d[GID_LEN] = COMPARE(d[GID_LEN], (long int)ft_strlen(gid->gr_name));
		}
	}
	return (0);
}

long int		*len_infos(char *nam,
				struct dirent **fil, int qty, char *o)
{
	long int			*d;
	struct stat			statf;
	char				*nam_made;
	int					i;

	if (!(d = malloc(sizeof(long int) *
		(MAX_LENS + 2 + (i = -1)))))
		return (NULL);
	ft_bzero(d, sizeof(long int) * MAX_LENS);
	while (++i < qty && lstat(nam_made =
		mknam(nam, fil[i]->d_name), &statf) == 0 && (d[3] = 1))
	{
		free(nam_made);
		compare_stock(d, statf, fil[i]->d_name, o);
	}
	if (d[BLK_CHR])
		d[SIZ_LEN] = ft_lintlen(d[MAJ_TMP]) + ft_lintlen(d[MIN_TMP]) + 2;
	else
		d[SIZ_LEN] = ft_lintlen(d[SIZ_TMP]);
	d[MIN_LEN] = ft_lintlen(d[MIN_TMP]);
	d[MAJ_LEN] = ft_lintlen(d[MAJ_TMP]);
	d[LNK_LEN] = ft_lintlen(d[LNK_TMP]);
	d[BLK_LEN] = ft_lintlen(d[BLK_TMP]);
	return (d);
}

char			*link_symlink(char *path_nam)
{
	t_stats		lstatf;
	char		*outp;
	char		buff[257];

	ft_bzero(buff, 257);
	outp = NULL;
	if (lstat(path_nam, &lstatf))
		return (NULL);
	if (lstatf.st_mode < S_IFLNK)
		return (NULL);
	else
		outp = ft_strnew(readlink(path_nam, buff, 256) + 5);
	ft_strcat(outp, " -> ");
	ft_strcat(outp, buff);
	return (outp);
}

void			put_total(long int blk_siz)
{
	char		*blk;

	pcat("total ", blk = ft_litoa(blk_siz), NULL, 1);
	free(blk);
}
