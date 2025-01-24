/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:02:42 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:47:47 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	temp = *lst;
	while (temp->next)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
