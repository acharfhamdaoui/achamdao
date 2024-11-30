/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:07:51 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:14:24 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex(char *str, unsigned long num)
{
	int		i;
	int		j;
	char	maxhex[16];

	i = 0;
	if (num == 0)
	{
		return (write(1, &str[0], 1));
	}
	while (num > 0)
	{
		maxhex[i] = str[num % 16];
		num /= 16;
		i++;
	}
	j = i;
	while ((--j) >= 0)
		write(1, &maxhex[j], 1);
	return (i);
}
