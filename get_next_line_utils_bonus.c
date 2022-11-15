/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:56 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 08:09:19 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len ++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		strjoin[j + i] = s2[j];
		j ++;
	}
	strjoin[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char			*dup_str;
	unsigned int	index;
	unsigned int	length;

	length = ft_strlen(s);
	dup_str = malloc((length + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup_str[index] = s[index];
		index ++;
	}
	dup_str[index] = '\0';
	return (dup_str);
}
