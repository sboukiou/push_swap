/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:15:16 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 17:15:31 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ref;
	t_node	*temp_ref;
	t_node	*temp_stack;

	ref = stack_duplicate(stack);
	if (!ref)
		return (0);
	stack_sort(ref);
	temp_ref = ref->top;
	temp_stack = stack->top;
	while (temp_ref)
	{
		if (temp_ref->value != temp_stack->value)
		{
			stack_free(ref);
			return (0);
		}
		temp_ref = temp_ref->next;
		temp_stack = temp_stack->next;
	}
	stack_free(ref);
	return (1);
}

