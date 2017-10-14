/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:06:31 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/14 18:35:15 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

void				mode_user(int mode, char *s)
{
	(mode & S_IRUSR) ? ft_strncat(s, "r", 1) : ft_strncat(s, "-", 1);
	(mode & S_IWUSR) ? ft_strncat(s, "w", 1) : ft_strncat(s, "-", 1);
	if (mode & S_IXUSR && !(mode & S_ISUID))
		ft_strncat(s, "x", 1);
	else if (mode & S_IXUSR && mode & S_ISUID)
		ft_strncat(s, "s", 1);
	else if (!(mode & S_IXUSR) && mode & S_ISUID)
		ft_strncat(s, "S", 1);
	else
		ft_strncat(s, "-", 1);
}

void				mode_grup(int mode, char *s)
{
	(mode & S_IRGRP) ? ft_strncat(s, "r", 1) : ft_strncat(s, "-", 1);
	(mode & S_IWGRP) ? ft_strncat(s, "w", 1) : ft_strncat(s, "-", 1);
	if (mode & S_IXGRP && !(mode & S_ISGID))
		ft_strncat(s, "x", 1);
	else if (mode & S_IXGRP && mode & S_ISGID)
		ft_strncat(s, "s", 1);
	else if (!(mode & S_IXGRP) && mode & S_ISGID)
		ft_strncat(s, "S", 1);
	else
		ft_strncat(s, "-", 1);
}

void				mode_othr(int mode, char *s)
{
	(mode & S_IROTH) ? ft_strncat(s, "r", 1) : ft_strncat(s, "-", 1);
	(mode & S_IWOTH) ? ft_strncat(s, "w", 1) : ft_strncat(s, "-", 1);
	if (mode & S_IXOTH && !(mode & S_ISVTX))
		ft_strncat(s, "x", 1);
	else if (mode & S_IXOTH && mode & S_ISVTX)
		ft_strncat(s, "t", 1);
	else if (!(mode & S_IXOTH) && mode & S_ISVTX)
		ft_strncat(s, "T", 1);
	else
		ft_strncat(s, "-", 1);
}

char				*translate_mod(int st_mode, char *str)
{
	if (S_ISLNK(st_mode))
		ft_strncat(str, "l", 1);
	else if (S_ISDIR(st_mode))
		ft_strncat(str, "d", 1);
	else if (S_ISREG(st_mode))
		ft_strncat(str, "-", 1);
	else if (S_ISBLK(st_mode))
		ft_strncat(str, "b", 1);
	else if (S_ISCHR(st_mode))
		ft_strncat(str, "c", 1);
	else if (S_ISFIFO(st_mode))
		ft_strncat(str, "p", 1);
	else if (S_ISSOCK(st_mode))
		ft_strncat(str, "s", 1);
	else
		ft_strncat(str, "u", 1);
	mode_user(st_mode, str);
	mode_grup(st_mode, str);
	mode_othr(st_mode, str);
	return (NULL);
}

void				append_uid_gid(char *str,
		t_stats statf, char *opt, long int *lns)
{
	struct group	*g_info;
	struct passwd	*u_info;
	char			*tmp;
	int				i;

	if (!opt[G])
	{
		u_info = getpwuid(statf.st_uid);
		tmp = u_info ? u_info->pw_name : ft_litoa((long int)statf.st_uid);
		ft_strncat(str, tmp, i = ft_strlen(tmp));
		while (i++ <= lns[UID_LEN] + 1)
			ft_strncat(str, " ", 1);
		!u_info ? free(tmp) : 1;
	}
	if (!opt[O])
	{
		g_info = getgrgid(statf.st_gid);
		tmp = g_info ? g_info->gr_name : ft_litoa((long int)statf.st_gid);
		ft_strncat(str, tmp, i = ft_strlen(tmp));
		while (i++ < lns[GID_LEN] + 1)
			ft_strncat(str, " ", 1);
		!g_info ? free(tmp) : 1;
	}
}
