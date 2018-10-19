/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:20:51 by gadant            #+#    #+#             */
/*   Updated: 2018/10/19 14:23:05 by gadant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (get_next_line(fd, &line))
	{
		ft_putstr("line :");
		ft_putendl(line);
	}
	close(fd);
	return (0);
}

