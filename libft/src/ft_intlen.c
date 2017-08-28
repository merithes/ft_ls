/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 19:28:57 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 19:45:37 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_intlen(int nb)
{
	unsigned int		pwr;
	unsigned int		i;
	unsigned int		n;

	pwr = 1;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		n = (unsigned int)-nb;
	}
	else
		n = (unsigned int)nb;
	while (pwr <= n)
	{
		pwr *= 10;
		i++;
	}
	return (i);
}
