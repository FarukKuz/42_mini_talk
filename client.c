/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:35:35 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/06 20:16:16 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	client_handler(int signal)
{
	if (signal == SIGUSR1)
		printf("deneme");

}

int	main(void)
{
	static char		c;
	static size_t	i;
	__pid_t			pid;

	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	printf("Sunucu PID'si: %d\n", getpid());
	pid = getpid();
	sa.sa_handler = client_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction hatasi");
		return (1);
	}
	printf("Sinyal bekliyor...\n");
	while (1)
	{
		usleep(1000);
		kill(pid, SIGUSR1);
	}

	/*
	c = 127;
	i = 0;
	printf("Once: %d\n", c);
	c = c >> 1;
	printf("Sonra2: %d\n", c);
	c += 1;
	printf("Sonra3: %d\n", c);
	c = 's';
	printf("Once: %c\n", c);
	c = c >> 1;
	printf("Sonra: %c\n", c);
	c = c + 1;
	c = c << 1; */
	kill(pid, SIGUSR1);
	return (0);
}
