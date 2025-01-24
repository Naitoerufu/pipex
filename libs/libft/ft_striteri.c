/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:36:29 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/11 17:50:00 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	count;

	if (!s || !f)
		return ;
	count = 0;
	while (s[count])
	{
		f(count, s + count);
		count++;
	}
}
