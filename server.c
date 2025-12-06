/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:56:20 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/06 20:23:01 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	server_handler(int sig_type)
{
	static char		c;
	static size_t	i;

	c = 0;
	i = 0;
	if (sig_type == SIGUSR1)
	{
		c = c << 1;
		i++;
	}
	if (sig_type == SIGUSR2)
	{
		c = c << 1;
		if (c == 0)
			c += 1;
		c = c * 2;
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = server_handler;
	printf("%d", pid);
	return (0);
}
