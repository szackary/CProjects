/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:00:55 by szackary          #+#    #+#             */
/*   Updated: 2022/01/17 14:01:03 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	put_address_letter(unsigned int n)
{
	if (n < 10)
		return ('0' + n);
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else
		return ('f');
}

static void	put_address_num(unsigned long n, int *len)
{
	char	s;

	if (n == 0)
		return ;
	else
	{
		put_address_num(n / 16, len);
		s = put_address_letter(n % 16);
		*len += write(1, &s, 1);
	}
}

void	ft_put_address(unsigned long n, int *len)
{
	*len += write(1, "0x", 2);
	if (n == 0)
		*len += write(1, "0", 1);
	else
		put_address_num(n, len);
}
