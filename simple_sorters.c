/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:48:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:28:10 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_size_three(t_stack *stack_a)
{
	t_node	*temp;

	temp = stack_a->top;
	if (temp->value < temp->next->value && temp->value < stack_a->bottom->value)
		return (rrab(stack_a, "rra\n"), sab(stack_a, "sa\n"));
	if (temp->value > temp->next->value && temp->value < stack_a->bottom->value)
		return (sab(stack_a, "sa\n"));
	if (temp->value < temp->next->value && temp->value > stack_a->bottom->value)
		return (rrab(stack_a, "rra\n"));
	if (temp->value > temp->next->value && temp->value > stack_a->bottom->value)
	{
		temp = temp->next;
		if (temp->value > temp->next->value)
		{
			sab(stack_a, "sa\n");
			return (rrab(stack_a, "rra\n"));
		}
		if (temp->value < temp->next->value)
		{
			rrab(stack_a, "rra\n");
			return (rrab(stack_a, "rra\n"));
		}
	}
}

void	sort_size_four_five(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*ref;

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);
	find_and_push_a(stack_a, stack_b, ref->top->value);
	if (stack_size(stack_a) == 4)
		find_and_push_a(stack_a, stack_b, ref->top->next->value);
	sort_size_three(stack_a);
	pab(stack_b, stack_a, "pa\n");
	pab(stack_b, stack_a, "pa\n");
}
