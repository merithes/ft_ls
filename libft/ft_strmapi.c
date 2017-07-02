/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <vboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:57:17 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/22 14:23:13 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	i;
	int				j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		if (!(fstr = (char *)malloc((j + 1) * sizeof(char))))
			return (NULL);
		while (s[i] != 0)
		{
			fstr[i] = f(i, s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
