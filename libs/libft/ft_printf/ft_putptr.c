/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:26:11 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/05 11:09:33 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putptr(void *ptr, int fd)
{
	unsigned long long	p;
	int					out;

	p = (unsigned long long)ptr;
	if (p == 0)
		return (ft_putstr_fd("(nil)", fd));
	out = ft_putstr_fd("0x", fd);
	out += ft_putlonghex(p, 1, fd);
	return (out);
}
