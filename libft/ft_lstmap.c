/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:59:15 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/11 19:16:24 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*keeptop;
	t_list	*outp;

	if (!lst)
		return (NULL);
	outp = f(lst);
	keeptop = outp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(outp->next = f(lst)))
		{
			free(outp->next);
			return (NULL);
		}
		outp = outp->next;
	}
	return (keeptop);
}
