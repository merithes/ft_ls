/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/05 11:02:16 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t amnt)
{
	const char	*src_char;
	char		*dest_char;

	src_char = (char *)src;
	dest_char = (char *)dest;
	if (dest_char <= src_char || src >= (dest + amnt))
	{
		while (amnt)
		{
			*dest_char++ = *src_char++;
			amnt--;
		}
	}
	else
	{
		src_char = src_char + amnt - 1;
		dest_char = dest_char + amnt - 1;
		while (amnt)
		{
			*dest_char-- = *src_char--;
			amnt--;
		}
	}
	return (dest);
}
