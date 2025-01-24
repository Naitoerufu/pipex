/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:56:50 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/08 12:23:37 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int	out;

	out = 0;
	while (num)
	{
		num /= 10;
		out++;
	}
	return (out);
}

static char	*ft_specialcheck(int n)
{
	char	*out;

	if (n == 2147483647)
	{
		out = ft_strdup("2147483647");
		return (out);
	}
	if (n == -2147483648)
	{
		out = ft_strdup("-2147483648");
		return (out);
	}
	if (n == 0)
	{
		out = ft_strdup("0");
		return (out);
	}
	return (NULL);
}

static	int	ft_sign(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (-1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		size;
	int		sign;

	out = ft_specialcheck(n);
	if (out)
		return (out);
	sign = ft_sign(&n);
	size = ft_numlen(n);
	out = malloc(size - sign + 1);
	if (!out)
		return (NULL);
	out[size - sign] = '\0';
	while (--size - sign >= 0)
	{
		out[size - sign] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		out[0] = '-';
	return (out);
}
