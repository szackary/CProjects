/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:43:09 by szackary          #+#    #+#             */
/*   Updated: 2021/11/10 21:35:39 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		i++;
	}
	return (i);
}

static char	*get_new_word(char const *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**mem_free(char **res, size_t i)
{
	size_t	n;

	n = 0;
	while (n < i)
	{
		free(res[n]);
		n++;
	}
	free(res);
	return (0);
}

static char	**add_words(char const *s, char c, size_t num, char **res)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < num)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		res[i] = get_new_word(s, len);
		if (!res[i])
			return (mem_free(res, i));
		s += len;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	num;

	if (!s)
		return (0);
	num = count_words(s, c);
	res = malloc(sizeof(char *) * (num + 1));
	if (!res)
	{
		return (0);
	}
	return (add_words(s, c, num, res));
}
