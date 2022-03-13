/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:14:26 by szackary          #+#    #+#             */
/*   Updated: 2022/01/20 12:48:42 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putnbr_fd(int n, int *fd);
void	ft_putstr_fd(char *s, int *fd);
void	ft_put_hexadecimal(unsigned int n, int *len, char c);
void	ft_put_address(unsigned long n, int *len);
int		ft_putchar_fd(char c, int *fd);
void	ft_put_unsignedint_fd(unsigned int n, int *fd);
int		ft_printf(const char *str, ...);

#endif
