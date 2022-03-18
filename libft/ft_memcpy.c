/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:00:35 by szackary          #+#    #+#             */
/*   Updated: 2021/10/24 01:11:35 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*pt_src;
	char		*pt_dst;

	pt_src = (char *)s2;
	pt_dst = (char *)s1;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (pt_dst == '\0' && pt_src == '\0')
		return (0);
	while (n--)
		*pt_dst++ = *pt_src++;
	return (s1);
}
