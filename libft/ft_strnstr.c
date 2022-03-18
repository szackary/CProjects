/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:10:45 by szackary          #+#    #+#             */
/*   Updated: 2021/11/09 18:15:03 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ndl[0] == '\0')
		return ((char *)hstck);
	while (hstck[i] && i < len)
	{
		j = 0;
		while (hstck[i + j] && ndl[j]
			&& i + j < len && hstck[i + j] == ndl[j])
		{
			j++;
			if (!ndl[j])
				return ((char *)(hstck + i));
		}
		i++;
	}
	return (0);
}
