/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:26:51 by gadant            #+#    #+#             */
/*   Updated: 2018/10/19 14:25:17 by gadant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			buffer[BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0 || fd < 0 || !line || (stock == NULL && \
		!(stock = ft_strnew(0))))
		return (-1);
	if (!(stock = read_line(stock, buffer, fd)))
		return (-1);
	if (*stock)
	{
		if (!(*line = stocker(&stock)))
			return (-1);
		if (!stock)
		{
			free(stock);
			stock = NULL;
		}
		return (1);
	}
	return (0);
}

char				*read_line(char *stock, char *buffer, int fd)
{
	int				ret;

	ret = 1;
	while (!(ft_strchr(stock, '\n')) && ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret > 0)
		{
			buffer[ret] = '\0';
			if (!(stock = ft_strjoin(stock, buffer)))
				return (NULL);
		}
	}
	return (stock);
}

char				*stocker(char **stock)
{
	char			*buffer;
	char			*line;

	buffer = ft_strchr(*stock, '\n');
	if (buffer)
	{
		if (!(line = ft_strndup(*stock, ft_strchr_index(*stock, '\n'))))
			return (NULL);
		*stock = *stock + ft_strchr_index(*stock, '\n') + 1;
	}
	else if (!(line = ft_strdup(*stock)))
		return (NULL);
	return (line);
}

int					ft_strchr_index(char *str, char c)
{
	int				i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (i == ft_strlen(str))
		return (0);
	return (i);
}

char				*ft_strndup(const char *str, int n)
{
	unsigned int	i;
	char			*s;

	if ((s = (char *)malloc(sizeof(char *) * (n))) == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
