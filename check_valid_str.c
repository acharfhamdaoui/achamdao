/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:17:55 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:14:21 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_modulo(char c)
{
	if (c == '%')
	{
		(write(1, &c, 1));
		return (0);
	}
	else
		return (1);
}

int	skeep_sep(const char *str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (is_flag(str[i]))
			n++;
		else if (is_format(str[i]))
			return (n);
		i++;
	}
	return (n);
}

int	check_valid_str(const char *pointer, va_list args)
{
	int	i;

	i = 0;
	while (*pointer)
	{
		if (*pointer == '%')
		{
			pointer++;
			if (is_format(*pointer))
				i += handle_printf(args, pointer);
			else if (print_modulo(*pointer))
				write(1, pointer, 1);
			i -= skeep_sep(pointer);
			i++;
			pointer += skeep_sep(pointer);
		}
		else
			write(1, pointer, 1);
		if (*pointer)
			pointer++;
	}
	return (i);
}
