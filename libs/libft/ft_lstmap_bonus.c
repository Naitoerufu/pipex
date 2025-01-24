/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:28:46 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 16:18:25 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;

	out = NULL;
	while (lst)
	{
		ft_lstadd_back(&out, ft_lstnew(f(lst->content)));
		if (!out)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (out);
}
