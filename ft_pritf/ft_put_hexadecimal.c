/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:50:36 by szackary          #+#    #+#             */
/*   Updated: 2022/01/18 18:50:42 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	put_hexadecimal_letter(unsigned int n, int flag)
{
	if (n < 10)
		return ('0' + n);
	else if (n == 10)
		return ('a' - flag);
	else if (n == 11)
		return ('b' - flag);
	else if (n == 12)
		return ('c' - flag);
	else if (n == 13)
		return ('d' - flag);
	else if (n == 14)
		return ('e' - flag);
	else
		return ('f' - flag);
}

static void	put_hexadecimal_num(unsigned int n, int *len, int flag)
{
	char	c;

	if (n == 0)
		return ;
	else
	{
		put_hexadecimal_num(n / 16, len, flag);
		c = put_hexadecimal_letter(n % 16, flag);
		*len += write (1, &c, 1);
	}
}

void	ft_put_hexadecimal(unsigned int n, int *len, char c)
{
	int	flag;

	if (c == 'x')
		flag = 0;
	else
		flag = 32;
	if (n == 0)
		*len += write (1, "0", 1);
	else
		put_hexadecimal_num(n, len, flag);
}
