/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:33:28 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:30:10 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (size < n && (s1[size] != '\0' || s2[size] != '\0'))
	{
		if (s1[size] < s2[size])
			return ((unsigned char)s1[size] - s2[size]);
		if (s2[size] < s1[size])
			return ((unsigned char)s1[size] - s2[size]);
		size++;
	}
	return (0);
}
