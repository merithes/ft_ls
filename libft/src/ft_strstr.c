/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:23:18 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 16:05:29 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_checkit(const char *big, const char *lil, int index)
{
	size_t i;

	i = 0;
	while ((big[index] == lil[i]) || lil[i] == '\0')
	{
		if (lil[i] == '\0')
			return (1);
		index++;
		i++;
	}
	return (0);
}

char			*ft_strstr(const char *big, const char *lil)
{
	size_t	i;

	i = 0;
	if (lil[0] == '\0')
		return ((char *)big);
	while (i <= ft_strlen((char *)big))
	{
		if (big[i] == lil[0])
			if (ft_checkit(big, lil, i))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
