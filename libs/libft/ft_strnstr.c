/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:57:25 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/12 15:13:43 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_size;
	size_t	count;
	size_t	check_count;

	if (len == 0 && (!little || !big))
		return (NULL);
	if (!(*little))
		return ((char *)big);
	lil_size = ft_strlen(little);
	count = 0;
	check_count = 0;
	while (big[count + lil_size - 1] && count + lil_size <= len)
	{
		if (big[count] == little[0])
		{
			while (big[count + check_count] == little[check_count]
				&& little[check_count])
				check_count++;
			if (!little[check_count])
				return ((char *)big + count);
			check_count = 0;
		}
		count++;
	}
	return (NULL);
}
