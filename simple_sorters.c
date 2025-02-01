/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:48:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/01 20:50:21 by sboukiou         ###   ########.fr       */
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
