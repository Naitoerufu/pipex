/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:11:35 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:16 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const to_check, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (to_check == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		start;
	int		end;

	start = 0;
	while (s1[start])
	{
		if (!(ft_inset(s1[start], set)))
			break ;
		start++;
	}
	end = ft_strlen(s1);
	while (end > start)
	{
		if (!(ft_inset(s1[end - 1], set)))
			break ;
		end--;
	}
	out = malloc(end - start + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1 + start, end - start + 1);
	return (out);
}
