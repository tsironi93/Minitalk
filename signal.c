/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:13 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 17:48:09 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	i = 0;
	p = (unsigned char *)ptr;
	val = (unsigned char)value;
	while (i < num)
	{
		p[i] = val;
		i++;
	}
	return (ptr);
}

void	signal_control(int signal_input, void *signal_control, int f)
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof(sigact));
	if (f)
	{
		sigact.sa_flags = SA_SIGINFO;
		sigact.sa_sigaction = signal_control;
	}
	else
		sigact.sa_handler = signal_control;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(signal_input, &sigact, NULL) < 0)
		exit(EXIT_FAILURE);
}

void	signal_kill(pid_t pid, int signmb)
{
	if (kill(pid, signmb) < 0)
	{
		ft_printf("KILL FAILED");
		exit(EXIT_FAILURE);
	}
}
