/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 21:45:48 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/02 21:53:57 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hls.h"

int		main(int ac, char **av)
{
	stats statf;

	if (lstat(av[1], &statf))
		return NULL;
	else
		printf("%d\t%d\t%d\t%d\n", statf.st_mode, S_IFREG, S_IFDIR, S_IFLNK);
}
