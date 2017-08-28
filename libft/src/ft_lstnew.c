/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:22:47 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/30 18:04:16 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*outp;

	if (!(outp = malloc(sizeof(*outp))))
		return (NULL);
	if (!content)
	{
		outp->content = NULL;
		outp->content_size = 0;
	}
	else
	{
		if (!(outp->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(outp->content, content, content_size);
		outp->content_size = content_size;
	}
	outp->next = NULL;
	return (outp);
}
