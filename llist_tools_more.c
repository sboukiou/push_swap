/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_tools_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:29:10 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:37:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	stack_issorted(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	while (temp)
	{
		if (temp->next && temp->next->value < temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	remove_at_top(t_stack *stack, t_node *node)
{
	stack->top = node->next;
	if (stack->bottom == node)
		stack->bottom = NULL;
	node->next = NULL;
	return ;
}

void	stack_remove(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (!stack || !node || !stack->top)
		return ;
	if (stack->top == node)
		return (remove_at_top(stack, node));
	temp = stack->top;
	while (temp)
	{
		if (temp->next == node)
		{
			if (stack->bottom == node)
			{
				stack->bottom = temp;
				temp->next = NULL;
			}
			if (node->next)
				temp->next = node->next;
			node->next = NULL;
			return ;
		}
		temp = temp->next;
	}
}

int	stack_index_of(t_stack *stack, int value)
{
	t_node	*temp;
	int		index;

	index = 0;
	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (index);
		temp = temp->next;
		index++;
	}
	return (index);
}

t_stack	*stack_duplicate(t_stack *stack)
{
	t_stack			*new_stack;
	t_node			*temp;
	t_node			*copy;

	if (!stack)
		return (NULL);
	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	temp = stack->top;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	while (temp)
	{
		copy = new_node(temp->value);
		if (!copy)
			return (stack_free(new_stack), NULL);
		stack_push_back(new_stack, copy);
		temp = temp->next;
	}
	return (new_stack);
}
