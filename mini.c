/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:38 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/21 08:45:59 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	control(int signal_input, siginfo_t *info, void *rest)
{
	static char		a;
	static int		bit;
	static pid_t	mini;


	(void)rest;
	if (info->si_pid)
		mini = info->si_pid;
	if (signal_input == SIGUSR1)
		a |= (0x80 >> bit);
	if (signal_input == SIGUSR2)
		a &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (a == '\0')
		{
			write(STDOUT_FILENO, "\n", 1);
			signal_kill(mini, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &a, 1);
	}
	signal_kill(mini, SIGUSR1);
}

int	main(void)
{
	printf("Talk PID = %d\n", getpid());
	signal_control(SIGUSR1, control, true);
	signal_control(SIGUSR2, control, true);
	while (1)
	{
		pause ();
	}
	exit(EXIT_SUCCESS);
}
