/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:31:45 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/02/26 18:31:59 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(unsigned long n)
{
	int				len;
	unsigned long	remainder;
	char			hex_char;

	len = 0;
	if (n >= 16)
		len += ft_puthex_p(n / 16);
	remainder = n % 16;
	if (remainder < 10)
	{
		len += ft_putchar('0' + remainder);
	}
	else
	{
		hex_char = 'a' + (remainder - 10);
		len += ft_putchar(hex_char);
	}
	return (len);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	int				len;
	unsigned int	remainder;
	char			hex_char;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, uppercase);
	remainder = n % 16;
	if (remainder < 10)
	{
		len += ft_putchar('0' + remainder);
	}
	else
	{
		if (uppercase)
			hex_char = 'A' + (remainder - 10);
		else
			hex_char = 'a' + (remainder - 10);
		len += ft_putchar(hex_char);
	}
	return (len);
}
