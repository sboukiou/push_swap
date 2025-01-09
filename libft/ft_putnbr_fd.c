/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:49:54 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/29 02:24:50 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_handle_sign(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return ((unsigned int)-n);
	}
	return ((unsigned int)n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	char			buffer[20];

	ft_bzero(buffer, 20);
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	number = ft_handle_sign(n, fd);
	ft_bzero(buffer, 20);
	n = 0;
	while (number > 0)
	{
		buffer[n++] = (number % 10) + '0';
		number /= 10;
	}
	while (n > 0)
	{
		ft_putchar_fd(buffer[n - 1], fd);
		n--;
	}
}
