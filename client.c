/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:35:35 by fakuz             #+#    #+#             */
/*   Updated: 2025/12/13 23:11:07 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static volatile int	g_ack;

static void	ack_handler(int sig_type)
{
	(void)sig_type;
	g_ack = 1;
}

static void	send_char(int pid, char c)
{
	int	bit;
	int	retry;

	bit = 7;
	while (bit >= 0)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		retry = 0;
		while (!g_ack && retry < 100)
		{
			usleep(100);
			retry++;
		}
		if (!g_ack)
		{
			ft_printf("Error: Server not responding\n");
			exit(1);
		}
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3 || ft_strlen(argv[1]) > 7)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\n');
	return (0);
}
