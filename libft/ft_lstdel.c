/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:59:03 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/09 19:52:47 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*getnext;
	t_list	*temp;

	getnext = *alst;
	while (getnext != NULL)
	{
		temp = getnext->next;
		del(getnext->content, getnext->content_size);
		free(getnext);
		getnext = temp;
	}
	*alst = NULL;
}
