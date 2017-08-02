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

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

void	print_nbrs(int *nbr)
{
	ft_putchar(nbr[0] + '0');
	ft_putchar(nbr[1] + '0');
	ft_putchar(nbr[2] + '0');
	if (nbr[0] != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int		main(int ac, char **av)
{
	int nbr[3];

	nbr[0] = 0;
	nbr[1] = 0;
	nbr[2] = 0;

	while (nbr[0] < 8)
	{
		nbr[1] = nbr[0] + 1;
		while (nbr[1] < 9)
		{
			nbr[2] = nbr[1] + 1;
			while (nbr[2] <= 9)
			{
				if (nbr[0] < nbr[1] && nbr[1] < nbr[2])
					print_nbrs(nbr);
				nbr[2]++;
			}
			nbr[1]++;
		}
		nbr[0]++;
	}
}
