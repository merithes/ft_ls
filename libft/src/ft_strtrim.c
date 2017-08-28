/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:27:37 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/02 19:52:09 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		srt;
	int		len;
	char	*outp;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	srt = 0;
	while (s[srt] == ' ' || s[srt] == '\t' || s[srt] == '\n')
		srt++;
	if (srt == len)
		return (NULL);
	len--;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	outp = (char *)malloc(sizeof(char) * (len - srt + 1));
	if (len == (int)(ft_strlen(s) - 1) && srt == 0)
		return (ft_strcpy(outp, s));
	len = len - srt;
	if (len <= 0)
		return (NULL);
	if (!(outp = ft_strsub(s, srt, len)))
		return (NULL);
	return (outp);
}
