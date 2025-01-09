/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:51:56 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/27 21:54:57 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_array(char *arr)
{
	int		index;
	int		j;
	char	temp;

	index = 0;
	j = ft_strlen(arr) - 1;
	while (index < j)
	{
		temp = arr[index];
		arr[index] = arr[j];
		arr[j] = temp;
		index++;
		j--;
	}
}

static size_t	count_buff_size(int i)
{
	unsigned int	num;
	int				length;

	length = 0;
	if (i < 0)
	{
		num = -i;
		length++;
	}
	else
		num = i;
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

static char	*creat_zero(void)
{
	char	*buff;

	buff = ft_calloc(2, sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = '0';
	return (buff);
}

char	*ft_itoa(int n)
{
	char			*buff;
	int				i;
	unsigned int	nbr;

	if (n == 0)
		return (creat_zero());
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	buff = ft_calloc(count_buff_size(n) + 1, sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (nbr > 0)
	{
		buff[i] = (nbr % 10) + '0';
		i++;
		nbr = nbr / 10;
	}
	if (n < 0)
		buff[i] = '-';
	reverse_array(buff);
	return (buff);
}
