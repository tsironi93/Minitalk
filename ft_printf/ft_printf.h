/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:34:15 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 19:14:48 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	convert_pto_hex(long int i, int fd, int count);
int	convert_to_caphex(int i, int fd, int count);
int	convert_to_hex(int i, int fd, int count);
int	ft_conversions(const char *str, va_list args, int count);
int	ft_printf(const char *str, ...);
int	ft_putnbr_fd(int n, int fd, int count);
int	ft_putstr_fd(char *s, int fd, int count);
int	print_pointer_hex(void *ptr, int fd, int count);
int	unsigned_casting(int i, int fd, int count);
int	ft_putchar_fd(char c, int fd, int count);

#endif
