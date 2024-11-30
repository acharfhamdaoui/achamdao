/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:00:47 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:29:42 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *pointer, ...)
{
	va_list	args;
	int		i;

	if (write(1, "", 1) == -1)
		return (-1);
	va_start(args, pointer);
	i = cat_formates_in_str(pointer);
	i += check_valid_str(pointer, args);
	va_end(args);
	return (i);
}
