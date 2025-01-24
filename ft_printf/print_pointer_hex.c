/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:14:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 19:16:27 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_hex(void *ptr, int fd, int count)
{
	uintptr_t	address;

	address = (uintptr_t)ptr;
	count = ft_putchar_fd('0', 1, count);
	count = ft_putchar_fd('x', 1, count);
	count = convert_pto_hex(address, fd, count);
	return (count);
}
