/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:49:44 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/05 11:07:11 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_fapply(char param, va_list arg, int fd)
{
	int	out;

	out = 0;
	if (param == 'c')
		out = ft_putchar_fd(va_arg(arg, int), fd);
	if (param == 's')
		out = ft_putstr_fd(va_arg(arg, char *), fd);
	if (param == 'p')
		out = ft_putptr(va_arg(arg, void *), fd);
	if (param == 'd' || param == 'i')
		out = ft_putnbr_fd(va_arg(arg, int), fd);
	if (param == 'u')
		out = ft_putu(va_arg(arg, int), fd);
	if (param == 'x')
		out = ft_puthex(va_arg(arg, int), 1, fd);
	if (param == 'X')
		out = ft_puthex(va_arg(arg, int), -1, fd);
	if (param == '%')
		out = ft_putchar_fd('%', fd);
	return (out);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	args;
	int		out;
	int		count;
	int		arg_pos;

	va_start(args, s);
	arg_pos = 0;
	count = 0;
	out = 0;
	while (s[count])
	{
		while (s[count] != '%' && s[count])
		{
			out += ft_putchar_fd(s[count], fd);
			count++;
		}
		if (s[count + 1] && s[count])
		{
			count++;
			out += ft_fapply(s[count], args, fd);
			count++;
		}
	}
	va_end(args);
	return (out);
}
