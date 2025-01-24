/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:42:38 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:28:47 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_hex(int i, int fd, int count)
{
	unsigned int	u;
	char			*hex;

	u = (unsigned int) i;
	hex = "0123456789abcdef";
	if (u / 16 > 0)
		count = convert_to_hex(u / 16, fd, count);
	count = ft_putchar_fd(hex[u % 16], fd, count);
	return (count);
}
