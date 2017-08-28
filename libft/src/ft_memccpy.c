/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/08 14:53:07 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t amnt)
{
	unsigned char		*src_char;
	unsigned char		*dest_char;
	size_t				i;

	if (dest == src)
		return (dest);
	i = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (i < amnt)
	{
		dest_char[i] = src_char[i];
		if (dest_char[i] == (unsigned char)c)
			return (dest_char + i + 1);
		i++;
	}
	return (NULL);
}
