#include "hls.h"

struct dirent	**_filter(char *inp)
{
	struct dirent	**tab_out;

	if (!inp || inp[0] == '-')
		return NULL;
	if(!(tab_out = malloc(sizeof(struct dirent *) * 6)))
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
	(outp = ft_strnew(len));
	ft_bzero(outp, len);
	if (ft_strcmp(s1, "/"))
		ft_strcpy(outp, s1);
	ft_strcat(outp, "/");
	ft_strcat(outp, s2);
	return (outp);
}

void			printd(int *order, struct dirent **content, int qty, char *opt)
{
	int			i;
	int			witness;

	i = 0;
	while (++i < qty)
		if (content[order[i]]->d_name[0] != '.' || (opt && opt[A]))
		{
			if (i % 6 == 0 && i != 0)
				ft_putchar('\n');
			ft_putstr_cat(content[order[i]]->d_name, NULL, NULL, witness++ * 0);
			ft_putnbr(content[order[i]]->d_type);
			ft_putchar('\t');
		}
	ft_putchar('\n');
}

void			list_tool(char *opt, struct dirent **content, char *nam, int qty)
{
	int				*order;
	char			*tmp;
	int				i;

	order = sort(opt, content, qty);
	printd(order, content, qty, opt);
	i = -1;
	while (++i < qty && (opt && opt[REC]))
		if (content[order[i]]->d_type == 4 && (((opt && opt[REC]) &&
				(ft_strcmp(content[order[i]]->d_name, ".") != 0 &&
					ft_strcmp(content[order[i]]->d_name, "..") != 0)) &&
						((content[order[i]]->d_name[0] != '.') ||
							(opt && opt[A]))))
		{
			list_dir(opt, (tmp = mknam(nam, content[order[i]]->d_name)));
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

void			list_dir(char *opt, char *av)
{
	int				i;
	DIR				*dir_id;
	struct dirent	**readtab;

	i = -1;
	if (!(readtab = _filter(av)))
		return ;
	if (opt && opt[REC])
		ft_putstr_cat(av, ":", NULL, 1);
	dir_id = opendir(av);
	while (++i >= 0)
	{
		if (!(readtab[i] = readdir(dir_id)))
			break ;
		if ((i + 1) % 5 == 0 && i != 0)
			readtab = realloc_dirent(readtab, i + 5);
	}
	list_tool(opt, readtab, av, i);
}
