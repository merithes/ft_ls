/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:43:28 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 16:34:18 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	int		temp;
	long	nb;

	nb = (long)n;
	i = 1;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	while (nb >= i)
		i *= 10;
	while (i / 10)
	{
		temp = (nb / (i / 10));
		ft_putchar_fd('0' + temp, fd);
		i /= 10;
		nb = nb - (temp * i);
	}
}
