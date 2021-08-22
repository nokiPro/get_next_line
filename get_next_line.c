/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daiki-ogawa <daiki-ogawa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:10 by daiki-ogawa       #+#    #+#             */
/*   Updated: 2021/08/21 17:05:44 by daiki-ogawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;
	int			status;
	size_t		read_size;

	read_size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = CONTINUE_READ;
	if (save)
		;
	else
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		while (1)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			buf[read_size] = '\0';
			if (ft_strchr(buf, '\n'))
			{
				save = ft_strjoin(save, ft_split(buf, '\n')[0]);// 改行前と後を切り分ける
				break ;
			}
			else
			{
				save = ft_strjoin(save, buf);
			}
		}
		printf("%s\n", save);
	}

	// printf("%d", fd);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	fd = open(av[1], O_RDONLY);
	char	*str = get_next_line(fd);
	while (1)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
