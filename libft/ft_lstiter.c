/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:59:03 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/09 12:05:04 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *alst, void (*f)(t_list *elem))
{
	t_list	*getnext;
	t_list	*temp;

	getnext = alst;
	while (getnext != NULL)
	{
		temp = getnext->next;
		f(getnext);
		getnext = temp;
	}
}
