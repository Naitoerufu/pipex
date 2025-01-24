/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:26:11 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/04 13:43:07 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	p;
	int					out;

	p = (unsigned long long)ptr;
	if (p == 0)
		return (ft_putstr("(nil)"));
	out = ft_putstr("0x");
	out += ft_putlonghex(p, 1);
	return (out);
}
