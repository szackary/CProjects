/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szackary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:16:55 by szackary          #+#    #+#             */
/*   Updated: 2021/12/27 20:42:10 by szackary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*buff(char *buf)
{
	char		*findn;
	char		*str_buf;
	int			len;

	findn = ft_strchr(buf, '\n');
	if (findn)
	{
		len = findn - &buf[0];
		ft_memcpy(buf, findn + 1, BUFFER_SIZE - len);
		buf[BUFFER_SIZE - len] = '\0';
	}
	else
		ft_bzero(buf, BUFFER_SIZE);
	findn = ft_strchr(buf, '\n');
	if (findn)
	{
		len = findn - &buf[0];
		if (findn == &buf[0])
			return (ft_substr("\n", 0, 1));
		str_buf = ft_substr(buf, 0, len + 1);
	}
	else
		str_buf = ft_substr("\0", 0, 1);
	return (str_buf);
}

char	*str_ret_s(char *buf)
{
	char		*str_ret;

	if (*buf)
		str_ret = ft_substr(buf, 0, ft_strlen(buf));
	else
		str_ret = ft_substr("\0", 0, 1);
	return (str_ret);
}

char	*ft_read(int fd, char *buf)
{
	char	*findn;
	char	*str_ret;
	int		buf_read;

	buf_read = 1;
	str_ret = str_ret_s(buf);
	while (!ft_strchr(buf, '\n') && buf_read > 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		buf_read = read(fd, buf, BUFFER_SIZE);
		if (buf_read < 0 || (buf_read == 0 && str_ret[0] == '\0'))
		{
			free(str_ret);
			return (NULL);
		}
		if (buf_read == 0)
			return (str_ret);
		str_ret = ft_strjoin(str_ret, buf);
	}
	findn = ft_strchr(str_ret, '\n');
	*(findn + 1) = '\0';
	return (str_ret);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str_buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str_buf = buff(buf);
	if (*str_buf || !str_buf)
		return (str_buf);
	free(str_buf);
	str_buf = ft_read(fd, buf);
	return (str_buf);
}
