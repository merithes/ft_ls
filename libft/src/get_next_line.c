/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:56:14 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/30 15:49:18 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			readit(int fd, char **inp)
{
	char			*bufr;
	char			*outp;
	int				errn;
	int				i;

	outp = (!*inp) ? ft_strnew(BUFF_SIZE) : *inp;
	if (!(bufr = ft_strnew(BUFF_SIZE)) || !(outp))
		return (-1);
	i = 0;
	ft_bzero(bufr, BUFF_SIZE + 1);
	while ((errn = read(fd, bufr, BUFF_SIZE)) != 0 && (i++ + 1) != 0)
	{
		if ((errn == -1) || !(outp = free_join(outp, bufr)))
			return (-1);
		if (bufr[0] == '\n' || (strchr_int(bufr, '\n') != 0 &&
			(size_t)strchr_int(bufr, '\n') - 1 != ft_strlen(bufr)))
			break ;
		ft_bzero(bufr, BUFF_SIZE + 1);
	}
	free(bufr);
	*inp = outp;
	if (errn == 0 && i == 0)
		return (0);
	return (1);
}

static char			*shifter(char *inp, int movr, t_mem *stok, int fd)
{
	char			*outp;
	int				len;

	len = ft_strlen(inp) - ++movr;
	if (len >= 0)
	{
		if (!(outp = ft_strnew(len + 1)))
			return (NULL);
		if (inp[movr] && outp)
			ft_strcpy(outp, inp + movr);
	}
	else
		outp = NULL;
	if (inp)
		free(inp);
	while (stok->fd != fd)
		stok = stok->next;
	stok->mem = outp;
	return (outp);
}

static char			*lgetstr(int fd, t_mem **inp)
{
	t_mem		*defile;

	defile = *inp;
	if (!*inp)
	{
		*inp = malloc(sizeof(t_mem));
		(*inp)->mem = NULL;
		(*inp)->fd = fd;
		(*inp)->next = NULL;
		return ((*inp)->mem);
	}
	while (defile->next != NULL)
	{
		if (defile->fd == fd)
			return (defile->mem);
		defile = defile->next;
	}
	if (defile->fd == fd)
		return (defile->mem);
	defile->next = malloc(sizeof(t_mem));
	defile = defile->next;
	defile->fd = fd;
	defile->mem = NULL;
	defile->next = NULL;
	return (defile->mem);
}

int					get_next_line(int fd, char **line)
{
	static	t_mem	*stok;
	int				i;
	char			*workon;
	char			*outp;

	i = 0;
	workon = lgetstr(fd, &stok);
	if (fd < 0 || !line || BUFF_SIZE <= 0 ||
			(i = readit(fd, &workon)) == -1)
		return (-1);
	if (((i == 0) && !workon) || !workon[0])
	{
		line = NULL;
		return (0);
	}
	if (!(i = strchr_int(workon, '\n')))
		i = ft_strlen(workon) + 1;
	if (!(outp = ft_strnew(i)))
		return (-1);
	ft_strncpy(outp, workon, i - 1);
	workon = shifter(workon, i - 1, stok, fd);
	*line = outp;
	return (1);
}
