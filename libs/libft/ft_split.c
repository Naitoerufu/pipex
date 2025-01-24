/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:10 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/12 15:04:04 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static int	ft_wordcounter(char const *s, char c)
{
	int	count;
	int	out;

	count = 0;
	out = 0;
	while (s[count])
	{
		while (s[count] == c)
			count++;
		if (s[count])
			out++;
		while (s[count] && s[count] != c)
			count++;
	}
	return (out);
}

static char	**ft_free(char **s, int end)
{
	int	count;

	count = -1;
	while (++count < end)
		free(s[count]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		word_num;
	char	**out;

	out = malloc(sizeof(char *) * (ft_wordcounter(s, c) + 1));
	if (!out)
		return (NULL);
	count = 0;
	word_num = 0;
	while (s[count])
	{
		while (s[count] == c)
			count++;
		if (s[count])
		{
			out[word_num] = malloc(ft_length(s + count, c) + 1);
			if (!out[word_num])
				return (ft_free(out, word_num));
			ft_strlcpy(out[word_num++], s + count, ft_length(s + count, c) + 1);
		}
		while (s[count] != c && s[count])
			count++;
	}
	out[word_num] = NULL;
	return (out);
}
