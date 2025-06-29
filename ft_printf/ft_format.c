/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:00:30 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/02/25 19:00:32 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_putpointer(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		len += ft_puthex(va_arg(arg, unsigned int), 1);
	else if (c == '%')
	{
		len += write(1, "%%", 1);
	}
	return (len);
}
