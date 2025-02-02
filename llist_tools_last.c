/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_tools_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:18:19 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:23:44 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	stack_free(t_stack *stack)
{
	t_node	*temp;
	t_node	*to_free;

	if (!stack)
		return ;
	temp = stack->top;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	free(stack);
}

void	stack_swap(t_node *node_a, t_node *node_b)
{
	int	temp;

	temp = node_a->value;
	node_a->value = node_b->value;
	node_b->value = temp;
}

void	stack_sort(t_stack *stack)
{
	t_node	*temp;
	t_node	*node;

	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	while (temp)
	{
		node = stack->top;
		while (node->next)
		{
			if (node->value > node->next->value)
				stack_swap(node, node->next);
			node = node->next;
		}
		temp = temp->next;
	}
}
