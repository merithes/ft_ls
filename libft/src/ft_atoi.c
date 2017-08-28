/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:46:23 by vboivin           #+#    #+#             */
/*   Updated: 2017/04/03 19:51:28 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int isneg;

	i = 0;
	nb = 0;
	isneg = 0;
	while ((8 < str[i] && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		isneg = 1;
	}
	else if (str[i] == '+')
		i++;
	while ((48 <= str[i] && str[i] <= 57) && str[i])
	{
		nb *= 10;
		nb = nb + str[i] - '0';
		i++;
	}
	if (isneg == 1)
		return (-nb);
	return (nb);
}
