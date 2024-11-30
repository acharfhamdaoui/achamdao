/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:15:47 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:14:59 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_chr(char c)
{
	if (!c)
		return (1);
	return (write(1, &c, 1));
}

int	is_found(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	handle_printf_bo_hex(va_list args, const char *c)
{
	long	x;

	if (is_format_bonus(c) == 'X')
	{
		x = va_arg(args, long);
		if (is_found(c, '#') && x != 0)
			return (write(1, "0x", 2) + print_hex(1, x));
		else
			return (print_hex(1, x));
	}
	else if (is_format_bonus(c) == 'x')
	{
		x = va_arg(args, long);
		if (is_found(c, '#') && x != 0)
			return (write(1, "0x", 2) + print_hex(0, x));
		else
			return (print_hex(0, x));
	}
	else if (is_format_bonus(c) == 'p')
		return (print_hex(2, va_arg(args, unsigned long)));
	return (0);
}

int	handle_printf_bo_d(va_list args, const char *c)
{
	long	d;

	if (is_format_bonus(c) == 'd' || is_format_bonus(c) == 'i')
	{
		d = va_arg(args, int);
		if (is_space(c) && !is_found(c, '+') && d > 0)
			return (write(1, " ", 1) + ft_putstr_fd(ft_itoa(d), 1));
		else if (is_found(c, '+') && d >= 0)
			return (write(1, "+", 1) + ft_putstr_fd(ft_itoa(d), 1));
		return (ft_putstr_fd(ft_itoa(d), 1));
	}
	else if (is_format_bonus(c) == 'u')
	{
		d = va_arg(args, unsigned int);
		if (is_space(c) && !is_found(c, '+'))
			return (write(1, " ", 1) + (ft_itoa(d), 1));
		else if (is_found(c, '+'))
			return (write(1, "+", 1) + ft_putstr_fd(ft_itoa(d), 1));
		return (ft_putstr_fd(ft_itoa(d), 1));
	}
	else
		return (handle_printf_bo_hex(args, c));
	return (0);
}

int	handle_printf(va_list args, const char *c)
{
	if (*c == 'c')
		return (put_chr(va_arg(args, int)));
	else if (*c == 'd' || *c == 'i')
		return (ft_putstr_fd(ft_itoa(va_arg(args, int)), 1));
	else if (*c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (*c == 'u')
		return (ft_putstr_fd(ft_itoa(va_arg(args, unsigned int)), 1));
	else if (*c == 'X')
		return (print_hex(1, va_arg(args, long)));
	else if (*c == 'x')
		return (print_hex(0, va_arg(args, long)));
	else if (*c == 'p')
		return (print_hex(2, va_arg(args, unsigned long)));
	else
		return ((handle_printf_bo_d(args, c)));
	return (0);
}
