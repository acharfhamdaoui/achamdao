/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:09:38 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:15:29 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(short flag, long num)
{
	if (flag == 1)
		return (convert_hex("0123456789ABCDEF", num));
	else if (flag == 2)
		return (write(1, "0x", 2) + convert_hex("0123456789abcdef", num));
	else if (flag == 3)
		return (convert_hex("0123456789abcdef", num));
	else
		return (convert_hex("0123456789abcdef", num));
}
