/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:45 by szackary          #+#    #+#             */
/*   Updated: 2022/01/20 12:49:03 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int *fd)
{
	*fd += write(1, &c, 1);
	return (*fd);
}

void	ft_putstr_fd(char *s, int *fd)
{
	int	i;

	i = 0;
	if (s == 0)
		*fd += write(1, "(null)", 6);
	else
	{
		while (s[i] != '\0')
		{
			*fd += write(1, &s[i], 1);
			i++;
		}
	}
}
