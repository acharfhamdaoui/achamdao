/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_formates_in_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:13:08 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:14:16 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cat_formates_in_str(const char *str)
{
	int	count;

	count = ft_strlen(str);
	while (*str)
	{
		if (*str == '%')
		{
			count--;
			str++;
			if (is_format(*str))
				count--;
			if (is_format(is_format_bonus(str)))
				count--;
		}
		str++;
	}
	return (count);
}
