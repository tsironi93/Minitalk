/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:11:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 17:48:39 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MINITALK_H)
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

enum
{
	READY,
	BUZY,
};

void	signal_control(int signal_input, void *signal_control, int f);
void	signal_kill(pid_t pid, int signmb);

#endif // MINITALK_H
