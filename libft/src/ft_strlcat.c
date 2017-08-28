/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:29:06 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/07 14:15:05 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destm;
	size_t	i;

	i = 0;
	destm = 0;
	while (dest[destm] && destm < size)
		destm++;
	while (src[i] && i + destm < size - 1)
	{
		dest[i + destm] = src[i];
		i++;
	}
	if (destm + i < size)
		dest[destm + i] = '\0';
	return (destm + ft_strlen(src));
}
