/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:42:48 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/07 19:07:09 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int chr)
{
	int i;

	i = 0;
	while (str[i] != (char)chr && str[i])
		i++;
	if (str[i] || (char)chr == '\0')
		return ((char *)str + i);
	return (NULL);
}
