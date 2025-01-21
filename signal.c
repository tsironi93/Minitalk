/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:13 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/21 08:46:04 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_control(int signal_input, void *signal_control, int f)
{
	struct sigaction	sigact = {0};

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
		perror("KILL FAILED");
		exit(EXIT_FAILURE);
	}
}
