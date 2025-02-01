/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_tools_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:29:10 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/01 20:36:55 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	stack_issorted(t_stack *stack)
{
	t_node *temp;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	while (temp)
	{
		if (temp->next && temp->next->value < temp->value)
			return (0);
		temp =  temp->next;
	}
	return (1);
}

void	stack_remove(t_stack *stack, t_node *node)
{
	t_node	*temp;
	t_node	*to_remove;

	if (!stack || !node || !stack->top)
		return ;
	if (stack->top == node)
	{
		if (stack->bottom == node)
			stack->bottom = NULL;
		stack->top = node->next;
		return ;
	}
	temp = stack->top;
	while (temp)
	{
		if (temp->next == node)
		{
			if (stack->bottom == node)
				stack->bottom = temp;
			to_remove = temp->next;
			temp->next = to_remove->next;
			return ;
		}
		temp = temp->next;
	}
}
