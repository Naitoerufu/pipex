/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:02:36 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/02 16:03:24 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	size;

	size = 0;
	while (s1[size] != '\0' || s2[size] != '\0')
	{
		if (s1[size] < s2[size])
			return ((unsigned char)s1[size] - s2[size]);
		if (s2[size] < s1[size])
			return ((unsigned char)s1[size] - s2[size]);
		size++;
	}
	return (0);
}
