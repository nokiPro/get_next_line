/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daiki-ogawa <daiki-ogawa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:13 by daiki-ogawa       #+#    #+#             */
/*   Updated: 2021/08/21 16:54:43 by daiki-ogawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1
# define CONTINUE_READ	-2

char	*get_next_line(int fd);
size_t	ft_strlen(char const *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_c);
char	**ft_split(char const *str, char charset);

#endif
