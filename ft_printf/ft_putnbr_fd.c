/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:25:38 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/13 15:01:22 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int count)
{
	unsigned int	i;

	if (n < 0)
	{
		count = ft_putchar_fd('-', fd, count);
		n *= -1;
	}
	i = n;
	if (i > 9)
	{
		count = ft_putnbr_fd(i / 10, fd, count);
		count = ft_putnbr_fd(i % 10, fd, count);
	}
	else
		count = ft_putchar_fd(i + '0', fd, count);
	return (count);
}
