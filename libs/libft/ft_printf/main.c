/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:49:44 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/04 13:43:28 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_fapply(char param, va_list arg)
{
	int	out;

	out = 0;
	if (param == 'c')
		out = ft_putchar(va_arg(arg, int));
	if (param == 's')
		out = ft_putstr(va_arg(arg, char *));
	if (param == 'p')
		out = ft_putptr(va_arg(arg, void *));
	if (param == 'd' || param == 'i')
		out = ft_putnbr(va_arg(arg, int));
	if (param == 'u')
		out = ft_putu(va_arg(arg, int));
	if (param == 'x')
		out = ft_puthex(va_arg(arg, int), 1);
	if (param == 'X')
		out = ft_puthex(va_arg(arg, int), -1);
	if (param == '%')
		out = ft_putchar('%');
	return (out);
}

int	ft_printf(const char *s, ...)
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
			out += ft_putchar(s[count]);
			count++;
		}
		if (s[count + 1] && s[count])
		{
			count++;
			out += ft_fapply(s[count], args);
			count++;
		}
	}
	va_end(args);
	return (out);
}
