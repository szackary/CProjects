/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:58 by szackary          #+#    #+#             */
/*   Updated: 2022/01/20 12:50:52 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_put_unsignedint_fd(unsigned int n, int *fd)
{
	unsigned int	j;
	char			c;

	if (n == 0)
	{
		*fd += write (1, "0", 1);
		return ;
	}
	j = n;
	if (j < 10)
	{
		c = j + '0';
		*fd += write(1, &c, 1);
	}
	else
	{
		ft_put_unsignedint_fd(n / 10, fd);
		ft_put_unsignedint_fd(n % 10, fd);
	}
}
