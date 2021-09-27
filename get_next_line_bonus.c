/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daiki-ogawa <daiki-ogawa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:10 by daiki-ogawa       #+#    #+#             */
/*   Updated: 2021/09/27 19:07:29 by daiki-ogawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	set_value(char **save, char **line, char *split_point)
{
	char	*tmp;

	if (split_point)
	{
		*line = ft_substr(*save, 0, split_point - *save + 1);
		tmp = ft_substr(split_point + 1, 0, ft_strlen(split_point));
		if (!(*line) || !tmp)
			return (ERROR);
		free(*save);
		*save = tmp;
		return (SUCCESS);
	}
	else
	{
		if (*save && **save == '\0')
		{
			*line = NULL;
			free(*save);
		}
		else
			*line = *save;
		*save = NULL;
		return (END_OF_FILE);
	}
}

int	read_fd(int fd, char **save, char **line, char **buf)
{
	ssize_t	read_size;
	char	*split_point;
	char	*tmp;

	while (1)
	{
		split_point = ft_strchr(*save, '\n');
		if (split_point)
			break ;
		read_size = read(fd, *buf, BUFFER_SIZE);
		if (read_size == -1)
			return (ERROR);
		if (read_size == 0)
			break ;
		(*buf)[read_size] = '\0';
		tmp = *save;
		*save = ft_strjoin(*save, *buf);
		if (!tmp)
			return (ERROR);
		free(tmp);
	}
	return (set_value(save, line, split_point));
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX + 1];
	char		*line;
	char		*buf;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	buf = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!save[fd] || !buf)
		return (NULL);
	status = read_fd(fd, &save[fd], &line, &buf);
	free(buf);
	if (status == ERROR || status == END_OF_FILE)
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	if (status == ERROR)
		return (NULL);
	return (line);
}
