/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:44:04 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/06 16:44:34 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n >= 10)
		size += ft_putunsigned(n / 10);
	size += ft_putchr((n % 10) + '0');
	return (size);
}
