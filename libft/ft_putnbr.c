/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:43:28 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 16:29:08 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	i;
	int		temp;
	long	nb;

	nb = (long)n;
	i = 1;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	while (nb >= i)
		i *= 10;
	while (i / 10)
	{
		temp = (nb / (i / 10));
		ft_putchar('0' + temp);
		i /= 10;
		nb = nb - (temp * i);
	}
}
