/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:17:53 by vboivin           #+#    #+#             */
/*   Updated: 2017/08/28 17:59:23 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nblen(long int nb)
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

static	char	*ft_excep(long int nb)
{
	if (nb == (long int)(((unsigned long int)-1) / 2) * -1)
		return (ft_strdup("-9223372036854775807"));
	else
		return (ft_strdup("0"));
}

char			*ft_litoa(long int nb)
{
	char	*outp;
	int		len;
	int		isneg;

	outp = NULL;
	if (nb == 0 || nb == (long int)(((unsigned long int)-1) / 2) * -1)
		return (ft_excep(nb));
	isneg = (nb < 0) ? 1 : 0;
	len = ft_nblen(nb);
	nb *= (nb < 0) ? -1 : 1;
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
