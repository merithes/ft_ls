/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:57:53 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/14 12:00:35 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenchar(int start, char *str, int c)
{
	while (str[start] && str[start] != c)
		start++;
	if (str[start] == c)
		return (start);
	return (-1);
}
