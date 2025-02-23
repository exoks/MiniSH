/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:41:41 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:16:28 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(const char *format, ...)
{
	va_list	ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
			ft_putstr_fd(va_arg(ptr, char *), 2);
		else
			ft_putchar_fd(*format, 2);
		format++;
	}
	va_end(ptr);
}
