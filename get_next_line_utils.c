/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daiki-ogawa <daiki-ogawa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:07 by daiki-ogawa       #+#    #+#             */
/*   Updated: 2021/08/21 16:54:21 by daiki-ogawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (!s[i])
			return (NULL);
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	i = 0;
	// strlcpy使える
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_c)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	// strlenではメモリ領域を破壊する可能性
	// strnlenだと安全
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_c <= dst_len)
		return (dst_len + src_len);
	// size_tだから足し算の方がいいかも
	while (i + dst_len + 1 < dst_c && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret, s2, s1_len + s2_len + 1);
	return (ret);
}

static size_t	count_one_element(char const *str, char charset)
{
	size_t	i;
	size_t	count;
	int		sep_flg;

	i = 0;
	count = 0;
	sep_flg = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == charset))
			sep_flg = 1;
		else if (sep_flg == 1)
		{
			sep_flg = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*make_one_element(char const *str, char charset)
{
	size_t	count;
	char	*tmp;

	count = 0;
	while (str[count] != '\0' && (str[count] != charset))
		count++;
	tmp = malloc(sizeof(char) * (count + 1));
	if (!tmp)
		return (NULL);
	count = 0;
	while (str[count] != '\0' && (str[count] != charset))
	{
		tmp[count] = str[count];
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}

static int	separation_function(char **tmp, char const *str, char charset)
{
	size_t	i;
	size_t	j;
	int		flg;

	i = 0;
	j = 0;
	flg = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == charset))
			flg = 1;
		else if (flg == 1)
		{
			tmp[j] = make_one_element(&str[i], charset);
			if (!tmp[j])
				return (1);
			flg = 0;
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *str, char charset)
{
	char		**tmp;
	size_t		size;
	size_t		i;

	if (!str)
		return (NULL);
	i = 0;
	size = count_one_element(str, charset);
	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	if (separation_function(tmp, str, charset) == 1)
	{
		while (!tmp[i])
			free(tmp[i++]);
		free(tmp);
		return (NULL);
	}
	tmp[size] = NULL;
	return (tmp);
}
