/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:37:39 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/31 03:17:38 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ov_num(int sign)
{
	if (sign == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	num = 0;
	while (ft_isdigit(*str))
	{
		if (num > LONG_MAX / 10)
			return (ov_num(sign));
		if (num == LONG_MAX / 10 && LONG_MAX % 10 < (*str - '0'))
			return (ov_num(sign));
		num = 10 * num + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}
