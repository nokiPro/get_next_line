/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daiki-ogawa <daiki-ogawa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:46:30 by daiki-ogawa       #+#    #+#             */
/*   Updated: 2021/09/27 19:07:19 by daiki-ogawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	ans;

	ans = 0;
	while (s[ans])
		ans++;
	return (ans);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			s_len;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	*substr = '\0';
	if (start >= ft_strlen(s))
		return (substr);
	i = 0;
	s_len = ft_strlen(s);
	while (i < len && i < s_len)
	{
		substr[i] = *(s + start + i);
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str || !c)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*ans;
	unsigned int	total_len;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(total_len + 1);
	if (!str)
		return (NULL);
	ans = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ans);
}
