/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:07:27 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/02 19:31:13 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t bytes_to_set)
{
	size_t			i;
	unsigned char	*chr_str;

	i = 0;
	chr_str = (unsigned char *)str;
	if (bytes_to_set == 0)
		return ;
	else
		while (i < bytes_to_set)
		{
			*chr_str++ = '\0';
			i++;
		}
}
