/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:46 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/30 15:12:04 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_talk = BUZY;

static int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	recieving_handler(void)
{
	g_talk = READY;
}

static void	ending_handler(void)
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
		if (a & (1 << (7 - bit)))
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
	talk = ft_atoi(av[1]);
	msg = av[2];
	signal_control(SIGUSR1, recieving_handler, 0);
	signal_control(SIGUSR2, ending_handler, 0);
	while (msg)
		sendmsg(*msg++, talk);
	sendmsg('\0', talk);
	exit (EXIT_SUCCESS);
}
