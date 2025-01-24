/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:21:47 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/07 11:44:00 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*out;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		out = ft_calloc(1, 1);
		return (out);
	}
	else
	{
		if (ft_strlen(s) <= len)
			len = ft_strlen(s) - start;
		out = malloc(len + 1);
		if (!out)
			return (NULL);
		count = 0;
		while (++count < len + 1 && start + count < ft_strlen(s) + 1)
			out[count - 1] = s[start + count - 1];
		out[count - 1] = '\0';
		return (out);
	}
}
