/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:23:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:44:15 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*out;

	if (!s || !f)
		return (NULL);
	out = ft_strdup(s);
	if (!out)
		return (NULL);
	count = 0;
	while (s[count])
	{
		out[count] = f(count, s[count]);
		count++;
	}
	return (out);
}
