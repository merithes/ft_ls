/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:58:08 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/01 23:00:52 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int pwr;

	pwr = 1;
	if (nb < 1)
		return (0);
	else if (nb > 1)
	{
		if (nb <= 256)
			while (pwr <= (nb / 2))
			{
				if (pwr * pwr == nb)
					return (pwr);
				pwr++;
			}
		else
			while (pwr <= (nb / 16))
			{
				if (pwr * pwr == nb)
					return (pwr);
				pwr++;
			}
		return (0);
	}
	return (1);
}
