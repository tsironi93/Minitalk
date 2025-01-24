/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_caphex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:21 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:28:44 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_caphex(int i, int fd, int count)
{
	unsigned int	u;
	char			*hex;

	u = (unsigned int) i;
	hex = "0123456789ABCDEF";
	if (u / 16 > 0)
		count = convert_to_caphex(u / 16, fd, count);
	count = ft_putchar_fd(hex[u % 16], fd, count);
	return (count);
}
