/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:56 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/21 08:45:55 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_talk = BUZY;

static void	recieving_handler(int signmb)
{
	g_talk = READY;
}

static void	ending_handler(int signmb)
{
	write(STDOUT_FILENO, "Ok Malaka!!!\n", 13);
	exit(EXIT_SUCCESS);
}

static void	sendmsg(char a, pid_t talk)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (a & (0x80 >> bit))
			signal_kill(talk, SIGUSR1);
		else
			signal_kill(talk, SIGUSR2);
		bit++;
		while (g_talk == BUZY)
			usleep (42);
		g_talk = BUZY;
	}
}

int	main(int ac, char **av)
{
	pid_t	talk;
	char	*msg;

	if (ac != 3)
		exit(EXIT_FAILURE);
	talk = atoi(av[1]);
	msg = av[2];
	signal_control(SIGUSR1, recieving_handler, 0);
	signal_control(SIGUSR2, ending_handler, 0);
	while (msg)
		sendmsg(*msg++, talk);
	sendmsg('\0', talk);
}