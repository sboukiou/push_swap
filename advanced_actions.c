/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:10:06 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:10:17 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	find_and_push_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	size_t	size_a;
	size_t	index;

	if (!stack_a || !stack_b)
		return ;
	size_a = stack_size(stack_a);
	index = stack_index_of(stack_a, value);
	while (stack_a->top->value != value)
	{
		if (size_a / 2 > index)
		{
			while (stack_a->top->value != value)
				rab(stack_a, "ra\n");
		}
		else
		{
			while (stack_a->top->value != value)
				rrab(stack_a, "rra\n");
		}
	}
	pab(stack_a, stack_b, "pb\n");
}

void	find_and_push_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	size_t	size_a;
	size_t	index;

	if (!stack_b || !stack_a)
		return ;
	size_a = stack_size(stack_b);
	index = stack_index_of(stack_b, value);
	while (stack_b->top->value != value)
	{
		if (size_a / 2 > index)
		{
			while (stack_b->top->value != value)
				rab(stack_b, "rb\n");
		}
		else
		{
			while (stack_b->top->value != value)
				rrab(stack_b, "rrb\n");
		}
	}
	pab(stack_b, stack_a, "pa\n");
}
