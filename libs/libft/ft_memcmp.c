/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:09:18 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/07 10:58:01 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s1)[count] != ((unsigned char *)s2)[count])
			return (((unsigned char *)s1)[count]
				- ((unsigned char *)s2)[count]);
		count++;
	}
	return (0);
}
