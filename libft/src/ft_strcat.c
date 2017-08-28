/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:21:01 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/08 15:07:24 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int isrc;
	int idest;

	idest = ft_strlen(dest);
	isrc = 0;
	while (src[isrc])
	{
		dest[idest++] = src[isrc++];
	}
	dest[idest] = '\0';
	return (dest);
}
