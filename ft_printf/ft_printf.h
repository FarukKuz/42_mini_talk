/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:10:48 by fakuz             #+#    #+#             */
/*   Updated: 2025/08/30 17:09:16 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_print_mem_adress(void *adr);
int		ft_print_hex(unsigned long nbr, char format);
int		ft_putunsigned(unsigned int n);

#endif