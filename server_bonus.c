/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:10:11 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/30 15:10:18 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	control(int signal_input, siginfo_t *info, void *rest)
{
	static char		a;
	static int		bit;
	static pid_t	pid;

	(void)rest;
	if (info->si_pid)
		pid = info->si_pid;
	if (signal_input == SIGUSR1)
		a |= (1 << (7 - bit));
	if (signal_input == SIGUSR2)
		a &= ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (a == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			signal_kill(pid, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &a, 1);
	}
	signal_kill(pid, SIGUSR1);
}

int	main(void)
{
	ft_printf("Talk PID = %d\n", getpid());
	signal_control(SIGUSR1, control, true);
	signal_control(SIGUSR2, control, true);
	while (1)
	{
		pause ();
	}
	exit(EXIT_SUCCESS);
}
