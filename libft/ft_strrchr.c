/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:42:48 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/07 14:39:08 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int i;
	int pos;

	i = 0;
	pos = -1;
	while (str[i])
	{
		if (str[i] == (char)chr)
			pos = i;
		i++;
	}
	if (chr == 0)
		return ((char*)str + i);
	if (pos >= 0)
		return ((char *)str + pos);
	return (NULL);
}
