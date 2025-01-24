/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:39:46 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:29:21 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_casting(int i, int fd, int count)
{
	unsigned int	u;

	u = (unsigned int) i;
	if (i >= 0)
		return (ft_putnbr_fd(i, fd, count));
	else
	{
		if (u > 10)
		{
			count = unsigned_casting(u / 10, fd, count);
			count = ft_putnbr_fd(u % 10, fd, count);
		}
		return (count);
	}
}
