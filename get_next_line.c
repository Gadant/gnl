/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:09:32 by ychahbar          #+#    #+#             */
/*   Updated: 2018/10/16 13:44:39 by gadant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_index(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (i == ft_strlen(str))
		return (0);
	return (i);
}

char	*joiner(char buffer[BUFF_SIZE + 1], char *str)
{
	if (str == NULL)
		str = ft_strdup(buffer);
	else
		str = ft_strjoin(str, buffer);
	return (str);
}

char	*ft_strndup(const char *str, int n)
{
	unsigned int		i;
	char				*s;

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

char	*stocker(char buffer[BUFF_SIZE + 1], char ***stock, char *str, int j)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tmp = NULL;
	if (j < BUFF_SIZE)
	{
		j++;
		i = j;
		if (!(tmp = (char *)malloc(sizeof(char *) * (BUFF_SIZE - 1))))
			return (NULL);
		while (buffer[i] && i < BUFF_SIZE)
			tmp[k++] = buffer[i++];
		tmp[k] = '\0';
		**stock = ft_strdup(tmp);
//		ft_putstr("stocker :");
//		ft_putstr(**stock);
//		ft_putstr("\n");
		free(tmp);
	}
	buffer[j - 1] = '\0';
	str = joiner(buffer, str);
//	ft_putstr("str stocker :");
//	ft_putstr(str);
//	ft_putstr("\n");
	return (str);
}

char	*read_line(char buffer[BUFF_SIZE + 1], int fd, char **stock)
{
	char			*str;
	int		ret;
	char	*tmp;
	int		j;

	str = NULL;
	if (ft_strchr_index(*stock, '\n') == 0 && *stock != NULL)
		str = ft_strdup(*stock);
	if (ft_strchr_index(*stock, '\n') != 0  && *stock != NULL)
	{
		str = ft_strndup(*stock, ft_strchr_index(*stock, '\n'));
		*stock = *stock + ft_strchr_index(*stock, '\n') + 1;
		ft_putstr("stock 2 :");
		ft_putendl(*stock);
		return (str);
	}
	ft_putstr("stock :");
	ft_putstr(*stock);
	ft_putstr("\n");
	*stock = NULL;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0 && buffer[j] != '\n')
	{
		buffer[ret] = '\0';
		j = 0;
		while (buffer[j] != '\n' && j <= ret)
			j++ == ret ? str = joiner(buffer, str) : 0;
//		buffer[j] == '\n' ? str = stocker(buffer, &stock, str, j) : 0;
		if (buffer [j] =='\n')
		{
			str = stocker(buffer, &stock, str, j);
			return (str);
		}
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char		*stock = NULL;

	*line = NULL;
	if (BUFF_SIZE <= 0 || fd < 0 || !line || (stock == NULL && 
	!(stock = ft_strnew(0))))
		return (-1);
	if (!(*line = read_line(buffer, fd, &stock)))
		return (-1);
	if (*read_line == NULL)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	if (get_next_line(fd, &line) == 1)
	{
		ft_putendl("AVANT :");
		ft_putstr("line :");
		ft_putendl(line);
		ft_putendl("APRES :");
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putendl("AVANT :");
		ft_putstr("line :");
		ft_putendl(line);
		ft_putendl("APRES :");
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	/*
	while (get_next_line(fd, &line))
	{
		ft_putstr("line :");
		ft_putendl(line);
	}*/
	close(fd);
	return (0);
}
