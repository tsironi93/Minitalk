/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:21:40 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/13 15:06:15 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int count)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (count + 6);
	}
	while (s[i])
		count = ft_putchar_fd(s[i++], fd, count);
	return (count);
}
