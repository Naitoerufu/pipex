/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:37:52 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/05 13:59:18 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s)[count] == (unsigned char)c)
			return ((void *)s + count);
		else
			count++;
	}
	return (NULL);
}
