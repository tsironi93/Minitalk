/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:38:10 by itsiros           #+#    #+#             */
/*   Updated: 2024/11/08 18:36:00 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str != '%')
			count = ft_putchar_fd(*str, 1, count);
		else
		{
			str++;
			count = ft_conversions(str, args, count);
		}
		str++;
	}
	va_end (args);
	return (count);
}
