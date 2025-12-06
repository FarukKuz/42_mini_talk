/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:35:35 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/06 15:30:17 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// void	client_handler(int	signal,)

int	main(void)
{
	static char		c;
	static size_t	i;

	c = 127;
	i = 0;
	printf("Once: %d\n", c);
	c = c >> 1;
	printf("Sonra2: %d\n", c);
	c += 1;
	printf("Sonra3: %d\n", c);
	c << 1;
	c = 's';
	printf("Once: %c\n", c);
	c = c >> 1;
	printf("Sonra: %c\n", c);
	return (0);
}
