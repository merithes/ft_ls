/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/06 20:04:46 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t amnt)
{
	const char	*src_char;
	char		*dest_char;

	src_char = (char *)src;
	dest_char = (char *)dest;
	while (amnt)
	{
		*dest_char++ = *src_char++;
		amnt--;
	}
	return (dest);
}
