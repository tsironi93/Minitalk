/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:15:11 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:28:58 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(const char *str, va_list args, int count)
{
	if (*str == '%')
		return (ft_putchar_fd('%', 1, count));
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1, count));
	if (*str == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1, count));
	if (*str == 'p')
		return (print_pointer_hex(va_arg(args, char *), 1, count));
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, count));
	if (*str == 'u')
		return (unsigned_casting(va_arg(args, int), 1, count));
	if (*str == 'x')
		return (convert_to_hex(va_arg(args, int), 1, count));
	if (*str == 'X')
		return (convert_to_caphex(va_arg(args, int), 1, count));
	return (count);
}
