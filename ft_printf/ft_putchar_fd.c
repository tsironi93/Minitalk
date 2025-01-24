/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:35:36 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:35:49 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int count)
{
	if (count < 0)
		return (count);
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
