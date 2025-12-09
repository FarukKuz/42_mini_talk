/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:58:25 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/06 15:57:59 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long nbr, char format)
{
	char	*base;
	int		size;

	size = 0;
	if (format == 'x' || format == 'p')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		size += ft_print_hex(nbr / 16, format);
	ft_putchr(base[nbr % 16]);
	return (size + 1);
}
