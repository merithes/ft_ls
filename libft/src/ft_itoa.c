/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:17:53 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/08 19:33:35 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isneg(long nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static	int		ft_absol(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static	int		ft_nblen(int nb)
{
	int		len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_excep(int nb)
{
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

char			*ft_itoa(int nb)
{
	char	*outp;
	int		len;
	int		isneg;

	outp = NULL;
	if (nb == 0 || nb == -2147483648)
		return (ft_excep(nb));
	isneg = ft_isneg(nb);
	len = ft_nblen(nb);
	nb = (long)ft_absol(nb);
	outp = (char *)malloc(sizeof(char) * (len + isneg + 1));
	if (outp)
	{
		if (isneg)
			outp[0] = '-';
		else
			len--;
		outp[len + 1] = '\0';
		while (nb)
		{
			outp[len--] = '0' + (nb % 10);
			nb /= 10;
		}
	}
	return (outp);
}
