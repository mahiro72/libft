/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 05:54:29 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/31 02:46:38 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static void	free_all(char **ptr, size_t	i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
}

static char	**split_strs(char const *s, char c, char **ptr, size_t cnt)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!ptr[i])
		{
			free_all(ptr, i);
			return (NULL);
		}
		ft_strlcpy(ptr[i], s, len + 1);
		s += len;
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	cnt;

	if (!s)
		return (NULL);
	cnt = count_strs(s, c);
	ptr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ptr)
		return (NULL);
	ptr = split_strs(s, c, ptr, cnt);
	if (!ptr)
		return (NULL);
	ptr[cnt] = NULL;
	return (ptr);
}
