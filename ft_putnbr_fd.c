/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshie <myoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 06:30:13 by myoshie           #+#    #+#             */
/*   Updated: 2022/05/29 18:34:37 by myoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = (unsigned int)(n * (-1));
		ft_putchar_fd('-', fd);
	}
	else
		un = (unsigned int)n;
	if (un >= 10)
		ft_putnbr_fd((int)(un / 10), fd);
	ft_putchar_fd((char)(un % 10 + '0'), fd);
}
