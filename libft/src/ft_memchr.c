/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:16:06 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/05 10:55:28 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int tocheck, size_t limit)
{
	size_t			i;
	unsigned char	*str_char;

	i = 0;
	str_char = (unsigned char *)str;
	while (i < limit)
	{
		if (str_char[i] == (unsigned char)tocheck)
			return ((void *)str_char + i);
		i++;
	}
	return (NULL);
}
