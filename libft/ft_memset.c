/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:07:27 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/04 16:26:01 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int chr, size_t bytes_to_set)
{
	size_t			i;
	unsigned char	*chr_str;

	i = 0;
	chr_str = (unsigned char *)str;
	if (bytes_to_set == 0)
		return (str);
	else
		while (i < bytes_to_set)
			chr_str[i++] = (unsigned char)chr;
	return (str);
}
