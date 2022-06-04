/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:40:12 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/27 03:21:22 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1len;

	s1len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1len + 1);
	return (ptr);
}
