/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem_adress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:40:18 by fakuz             #+#    #+#             */
/*   Updated: 2025/09/04 15:46:54 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_mem_adress(void *adr)
{
	int	size;

	size = 0;
	if (!(unsigned long) adr)
	{
		size += ft_putstr("(nil)");
		return (size);
	}
	size += ft_putstr("0x");
	size += ft_print_hex((unsigned long) adr, 'p');
	return (size);
}
