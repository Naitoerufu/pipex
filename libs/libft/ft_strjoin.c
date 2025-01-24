/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:52:17 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:42:31 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		out_size;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	out_size = ft_strlen(s1) + ft_strlen(s2);
	out = malloc(out_size + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, ft_strlen(s1) + 1);
	ft_strlcpy(out + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	out[out_size] = '\0';
	return (out);
}
