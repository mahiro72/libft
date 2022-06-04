/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 03:32:00 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/17 01:19:43 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxtlst;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		nxtlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxtlst;
	}
	*lst = NULL;
}
