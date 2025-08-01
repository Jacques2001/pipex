/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:24 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 14:48:10 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_format(const char *format, va_list args, int *i);
int	print_char(char c);
int	print_string(char *str);
int	print_nbr(int nb);
int	print_hex(unsigned int hex);
int	print_hexa(unsigned int nb);
int	print_address(void *ptr);
int	print_unsigned(unsigned int nb);

#endif