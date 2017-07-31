/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:22:20 by vboivin           #+#    #+#             */
/*   Updated: 2017/07/31 13:59:25 by vboivin          ###   ########.fr       */
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

int				*printd(struct dirent **file, int qty, char *opt)
{
	int			i;
	int			*order;

	order = sort(opt, file, qty);
	i = 0;
	while (++i < qty)
		if (file[order[i]]->d_name[0] != '.' || (opt && opt[A]))
		{
			ft_putstr(file[order[i]]->d_name);
			ft_putchar('\t');
			if (i && !(i % 4))
				ft_putchar('\n');
		}
	ft_putchar('\n');
	return (order);
}

char			*translate_mod(int st_mode, char *str, char a)
{
	int			mod[3];
	int			i;

	i = 3;
	ft_bzero(mod, sizeof(int) * 3);
	str[0] = a;
	mod[0] = st_mode % 8;
	mod[1] = ((st_mode - mod[0]) % 64) / 8;
	mod[2] = (st_mode - mod[0] - mod[1] * 8) / 64;
	while (--i >= 0)
		if (mod[i] == 1)
			ft_strncat(str, "--x", 3);
		else if (mod[i] == 2)
			ft_strncat(str, "-w-", 3);
		else if (mod[i] == 3)
			ft_strncat(str, "-wx", 3);
		else if (mod[i] == 4)
			ft_strncat(str, "r--", 3);
		else if (mod[i] == 5)
			ft_strncat(str, "r-x", 3);
		else if (mod[i] == 6)
			ft_strncat(str, "rw-", 3);
		else if (mod[i] == 7)
			ft_strncat(str, "rwx", 3);
	return (NULL);
}

void			append_uid_gid(char *str, int uid, int gid, long int *lns)
{
	struct group	*g_info;
	struct passwd	*u_info;
	int				i;

	g_info = getgrgid(gid);
	u_info = getpwuid(uid);
	ft_strncat(str, u_info->pw_name, i = ft_strlen(u_info->pw_name));
	while (i++ < lns[UID_LEN] + 1)
		ft_strncat(str, " ", 1);
	ft_strncat(str, g_info->gr_name, i = ft_strlen(g_info->gr_name));
	while (i++ < lns[GID_LEN] + 1)
		ft_strncat(str, " ", 1);
}

void			append_time(char *str, stats statf)
{
	char time_alpha[23];

	ft_bzero(time_alpha, sizeof(char) * 23);
	if (statf.st_mtime + SIX_MONTH > time(0))
		ft_strncat(str, ctime(&statf.st_mtime) + 4, 12);
	else
	{
		strcpy(time_alpha, ctime(&statf.st_mtime) + 4);
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

void			append_size(char *str, stats statf, long int *lengths)
{
	char		*size_alpha;
	size_t		len;

	if (!(size_alpha = ft_litoa(statf.st_size)))
		return ;
	len = ft_strlen(size_alpha);
	ft_strncat(str, size_alpha, len);
	free(size_alpha);
	while ((long int)len++ <= lengths[SIZ_LEN])
		ft_strncat(str, " ", 1);
}

char			*getstat(struct stat statf, char *str, long int *lengths)
{
	int			i;
	char		*tmp;

	ft_bzero(str, STRSIZE);
	i = 0;
	if (statf.st_mode >= S_IFLNK && 1 + (statf.st_mode -= S_IFLNK))
		translate_mod(statf.st_mode, str, 'l');
	else if (statf.st_mode < S_IFLNK && statf.st_mode >= S_IFREG &&
		1 + (statf.st_mode -= S_IFREG))
		translate_mod(statf.st_mode, str, '-');
	else if (statf.st_mode < S_IFREG && 1 + (statf.st_mode -= S_IFDIR))
		translate_mod(statf.st_mode, str, 'd');
	ft_strncat(str, " ", 1);
	ft_strncat(str, tmp = ft_itoa((int)statf.st_nlink),
		(i = ft_intlen((int)statf.st_nlink)));
	free(tmp);
	while (i++ < lengths[LNK_LEN] + 1)
		ft_strncat(str, " ", 1);
	append_uid_gid(str, statf.st_uid, statf.st_gid, lengths);
	append_size(str, statf, lengths);
	append_time(str, statf);
	return (str);
}

int				compare_stock(lsi *d, stats statf, char *name, char *o)
{
	struct passwd		*uid;
	struct group		*gid;

	uid = getpwuid(statf.st_uid);
	gid = getgrgid(statf.st_gid);
	if (d && uid && gid)
	{
		if (statf.st_size > d[0] && (name[0] != '.' || (o && o[A])))
			d[SIZ_TMP] = statf.st_size;
		d[UID_LEN] = COMPARE(d[UID_LEN], (long int)ft_strlen(uid->pw_name));
		d[GID_LEN] = COMPARE(d[GID_LEN], (long int)ft_strlen(gid->gr_name));
		d[LNK_TMP] = COMPARE((size_t)d[LNK_TMP], statf.st_nlink);
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
		(MAX_LENS + 1 + (i = 0)))))
		return (NULL);
	ft_bzero(d, sizeof(long int) * MAX_LENS);
	while (++i < qty && lstat(nam_made =
		mknam(nam, fil[i]->d_name), &statf) == 0 && (d[3] = 1))
	{
		free(nam_made);
		compare_stock(d, statf, fil[i]->d_name, o);
	}
	i = 1;
	while (d[SIZ_TMP] % i != d[SIZ_TMP] && ++d[SIZ_LEN])
		i *= 10;
	i = 1;
	while (d[LNK_TMP] % i != d[LNK_TMP] && ++d[LNK_LEN])
		i *= 10;
	return (d);
}

int				*printd_l(char *nam, struct dirent **file, int qty, char *opt)
{
	int				i;
	int				*order;
	struct stat		statf;
	char			*str_stat[2];
	long int		*infos_len;

	if (!(str_stat[0] = malloc(STRSIZE * sizeof(char))))
		return (NULL);
	i = -1;
	order = sort(opt, file, qty);
	infos_len = len_infos(nam, file, qty, opt);
	while (++i < qty)
		if ((file[order[i]]->d_name[0] != '.' || (opt && opt[A])) && !lstat(
			str_stat[1] = mknam(nam, file[order[i]]->d_name), &statf))
		{
			free(str_stat[1]);
			ft_putstr_cat((getstat(statf, str_stat[0], infos_len))
				, file[order[i]]->d_name, NULL, 1);
		}
	ft_putchar('\n');
	free(infos_len);
	free(str_stat[0]);
	return (order);
}

void			list_tool(char *opt, struct dirent **content,
				char *nam, int qty)
{
	int				*order;
	char			*tmp;
	int				i;
	DIR				*direc;

	if ((i = -1) && opt && opt[L])
		order = printd_l(nam, content, qty, opt);
	else
		order = printd(content, qty, opt);
	if (!order)
		return ;
	while (++i < qty && (opt && opt[REC]))
		if (content[order[i]]->d_type == 4 && (((opt && opt[REC]) &&
				(ft_strcmp(content[order[i]]->d_name, ".") != 0 &&
					ft_strcmp(content[order[i]]->d_name, "..") != 0)) &&
						((content[order[i]]->d_name[0] != '.') ||
							(opt && opt[A]))))
		{
			if ((direc = opendir(tmp = mknam(nam, content[order[i]]->d_name))))
				list_dir(opt, tmp, direc, 1);
			free(tmp);
		}
	free(order);
}

struct dirent	**realloc_dirent(struct dirent **inp, int size)
{
	int				i;
	struct dirent	**outp;

	i = 0;
	if (!(outp = malloc(sizeof(struct dirent *) * (size + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(struct dirent *) * size + 1);
	while ((outp[i] = inp[i]) && i < size)
		i++;
	free(inp);
	return (outp);
}

struct dirent	*mem_make_dirent(struct dirent *inp)
{
	struct dirent *outp;

	if (inp)
	{
		if (!(outp = malloc(sizeof(struct dirent))))
			return (NULL);
		ft_memcpy(outp, inp, sizeof(struct dirent));
	}
	else
		return (NULL);
	return (outp);
}

void			list_dir(char *opt, char *av, DIR *inp, int is_inp_not_null)
{
	int				i;
	DIR				*dir_id;
	struct dirent	**readtab;

	i = -1;
	if (!(readtab = f_ilter(av)))
		return ;
	if (opt && opt[REC])
		ft_putstr_cat(av, ":", NULL, 1);
	dir_id = (is_inp_not_null) ? inp : opendir(av);
	while (++i >= 0)
	{
		if (!(readtab[i] = mem_make_dirent(readdir(dir_id))))
			break ;
		if ((i + 1) % 5 == 0 && i != 0)
			readtab = realloc_dirent(readtab, i + 5);
	}
	list_tool(opt, readtab, av, i);
	i = 0;
	while (readtab[i++])
		free(readtab[i]);
	free(readtab);
	closedir(dir_id);
}
