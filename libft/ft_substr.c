/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:39:41 by szackary          #+#    #+#             */
/*   Updated: 2021/11/09 18:57:31 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	size_s;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (s1 == (void *)(0))
		return ((void *)(0));
	size_s = ft_strlen(s);
	while (i < len && i + start < size_s)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
