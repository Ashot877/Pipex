/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:51:29 by asmkrtch          #+#    #+#             */
/*   Updated: 2025/02/26 18:54:50 by asmkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putpointer(void *p);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_printf(const char *format, ...);
int	ft_puthex(unsigned int n, int c);
int	ft_puthex_p(unsigned long n);
int	ft_format(char c, va_list arg);

#endif
