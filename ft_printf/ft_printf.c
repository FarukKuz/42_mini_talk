/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:52:42 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/30 14:17:16 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list args, char format)
{
	int	sum;

	sum = 0;
	if (format == 'c')
		sum += ft_putchr(va_arg(args, int));
	if (format == 's')
		sum += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		sum += ft_print_mem_adress((va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		sum += ft_putnbr(va_arg(args, int));
	if (format == 'x' || format == 'X')
		sum += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == 'u')
		sum += ft_putunsigned(va_arg(args, unsigned int));
	if (format == '%')
		sum += ft_putchr(format);
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	sum;

	va_list(args);
	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			sum += check_type(args, str[i + 1]);
			i += 2;
		}
		else
		{
			sum += ft_putchr(str[i]);
			i++;
		}
	}
	va_end(args);
	return (sum);
}
