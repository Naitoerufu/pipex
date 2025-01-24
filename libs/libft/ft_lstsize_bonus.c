/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:32:40 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 16:18:45 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		out;
	t_list	*buf;

	if (!lst)
		return (0);
	out = 0;
	buf = lst;
	while (buf)
	{
		buf = buf->next;
		out++;
	}
	return (out);
}
