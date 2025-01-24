/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pto_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:08:50 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:28:39 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_pto_hex(long int i, int fd, int count)
{
	uintptr_t	u;
	char		*hex;

	u = (uintptr_t) i;
	hex = "0123456789abcdef";
	if (u / 16 > 0)
		count = convert_pto_hex(u / 16, fd, count);
	count = ft_putchar_fd(hex[u % 16], fd, count);
	return (count);
}
