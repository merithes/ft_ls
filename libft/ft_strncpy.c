/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:52:26 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/01 20:05:44 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t limit)
{
	size_t i;

	i = 0;
	ft_memset(dest, '\0', limit);
	while (src[i] && i < limit)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
