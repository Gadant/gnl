/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:20:09 by gadant            #+#    #+#             */
/*   Updated: 2018/11/02 12:21:56 by gadant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
char	*read_line(char *stock, char *buffer, int fd);
char	*stocker(char **stock);
int		ft_strchr_index(char *str, char c);
char	*ft_strndup(const char *str, int i);

#endif
