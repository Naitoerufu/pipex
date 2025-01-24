/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:09:30 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:01 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	int		count;

	out = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!out)
		return (NULL);
	count = -1;
	while (s[++count])
		out[count] = s[count];
	out[count] = '\0';
	return (out);
}
