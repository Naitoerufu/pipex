/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:21:32 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/05 13:26:14 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h" 

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	out;

	count = 0;
	out = ft_strlen(src);
	if (size == 0)
		return (out);
	while (count < size - 1 && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (out);
}
