/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:07:32 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/28 17:07:59 by vboivin          ###   ########.fr       */
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

char				*translate_mod(int st_mode, char *str, char a)
{
	ft_strncat(str, &a, 1);
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
	int				i;

	if (!opt[G])
	{
		u_info = getpwuid(statf.st_uid);
		ft_strncat(str, u_info->pw_name, i = ft_strlen(u_info->pw_name));
		while (i++ <= lns[UID_LEN] + 1)
			ft_strncat(str, " ", 1);
	}
	if (!opt[O])
	{
		g_info = getgrgid(statf.st_gid);
		ft_strncat(str, g_info->gr_name, i = ft_strlen(g_info->gr_name));
		while (i++ < lns[GID_LEN] + 1)
			ft_strncat(str, " ", 1);
	}
}
