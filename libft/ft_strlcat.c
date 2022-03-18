/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:53:34 by szackary          #+#    #+#             */
/*   Updated: 2021/10/25 18:39:18 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < dstsize)
		j++;
	while ((src[k]) && ((j + k + 1) < dstsize))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != dstsize)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
