/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 05:57:53 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/28 12:47:53 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	s_len;
	long	ln;

	ln = (long)n;
	s_len = get_len(ln);
	s = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!s)
		return (NULL);
	s[s_len] = '\0';
	if (ln == 0)
		s[0] = '0';
	if (ln < 0)
	{
		s[0] = '-';
		ln *= -1;
	}
	while (ln)
	{
		s[s_len - 1] = ln % 10 + '0';
		ln /= 10;
		s_len--;
	}
	return (s);
}
