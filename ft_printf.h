/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:33:51 by achamdao          #+#    #+#             */
/*   Updated: 2024/11/30 15:32:22 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(long n);
int		ft_putstr_fd(char *s, int fd);
int		convert_hex(char *str, unsigned long num);
int		print_hex(short flag, long num);
int		cat_formates_in_str(const char *str);
int		handle_printf(va_list args, const char *c);
int		check_valid_str(const char *pointer, va_list args);
int		is_format(char c);
char	is_format_bonus(const char *c);
int		is_flag(char c);
int		is_space(const char *str);
int		ft_printf(const char *pointer, ...);

#endif
