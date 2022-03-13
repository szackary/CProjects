/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:14:12 by szackary          #+#    #+#             */
/*   Updated: 2022/01/17 11:39:42 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(int i, va_list arg, int *len, const char *str)
{
	if (str[i] == 'c')
		ft_putchar_fd((char)va_arg(arg, int), len);
	else if (str[i] == 's')
		ft_putstr_fd((char *)va_arg(arg, void *), len);
	else if (str[i] == 'p')
		ft_put_address((unsigned long)va_arg(arg, void *), len);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd(va_arg(arg, int), len);
	else if (str[i] == 'u')
		ft_put_unsignedint_fd(va_arg(arg, unsigned int), len);
	else if (str[i] == 'x' || str[i] == 'X')
		ft_put_hexadecimal(va_arg(arg, unsigned int), len, str[i]);
	else if (str[i] == '%')
		*len += write(1, &str[i], 1);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			check_format(++i, arg, &len, str);
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
