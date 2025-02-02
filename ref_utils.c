/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:19:08 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:27:51 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	expand_range(int *start, int *end, int size)
{
	if (*end < size)
		(*end)++;
	if (*start < *end)
		(*start)++;
}

void	array_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*create_ref_array(t_stack *stack)
{
	int		*ref;
	int		idx;
	t_node	*temp;

	if (!stack || !stack->top)
		return (NULL);
	ref = (int *)malloc(sizeof(int) * stack_size(stack));
	if (!ref)
		return (NULL);
	idx = 0;
	temp = stack->top;
	while (temp)
	{
		ref[idx] = temp->value;
		idx++;
		temp = temp->next;
	}
	array_sort(ref, idx);
	return (ref);
}

int	includes(int *ref, int value, int range)
{
	int	idx;

	idx = 0;
	while (idx <= range)
	{
		if (ref[idx] >= value)
			return (1);
		idx++;
	}
	return (0);
}
