/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:37:07 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/05 17:34:22 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	out;
	size_t	i;

	i = 0;
	out = 0;
	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[count] && count < size)
		count++;
	out = count + ft_strlen(src);
	while (count + 1 < size && src[i])
	{
		dst[count] = src[i];
		count++;
		i++;
	}
	if (count < size)
		dst[count] = '\0';
	return (out);
}
