/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:58:36 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/06 16:46:37 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (size + 11);
	}
	if (n < 0)
	{
		n = -n;
		size += ft_putchr('-');
	}
	if (n >= 10)
	{
		size += ft_putnbr(n / 10);
	}
	size += ft_putchr(n % 10 + '0');
	return (size);
}
