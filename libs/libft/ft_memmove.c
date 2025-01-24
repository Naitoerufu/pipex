/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:56:28 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:28:08 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	count;

	if (!src && !dest)
		return ((void *)dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		count = n - 1;
		while (count >= 0)
		{
			((char *)dest)[count] = ((char *)src)[count];
			count--;
		}
	}
	return ((void *)dest);
}
