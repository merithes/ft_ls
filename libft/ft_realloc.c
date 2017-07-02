/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:16:41 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/01 13:05:36 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_realloc(char *inp, int qty)
{
	char	*outp;
	int		i;

	i = 0;
	if (!(outp = malloc(qty + 1)))
		return (NULL);
	while (i <= qty)
		outp[i++] = 0;
	i = 0;
	while (inp[i] && i < qty)
	{
		outp[i] = inp[i];
		i++;
	}
	outp[i] = 0;
	free(inp);
	return (outp);
}
