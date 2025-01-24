/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:49:00 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:26:54 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	if (!dest && !src)
		return ((void *)dest);
	count = 0;
	while (count < n)
	{
		((char *)dest)[count] = ((char *)src)[count];
		count++;
	}
	return ((void *)dest);
}
