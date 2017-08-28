/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:50:01 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 16:31:14 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *str1, const char *str2, size_t tocomp)
{
	size_t			i;

	i = 0;
	while (i < tocomp && (str1[i] || str2[i]))
	{
		if ((str1[i] != str2[i]) || !str1[i] || !str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
