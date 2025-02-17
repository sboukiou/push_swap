/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:16:23 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:17:24 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*stack_new(t_node *top, t_node *bottom)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = top;
	new_stack->bottom = bottom;
	return (new_stack);
}

void	stack_push_back(t_stack *stack, t_node *node)
{
	if (!stack)
		return ;
	if (stack->bottom)
	{
		stack->bottom->next = node;
		stack->bottom = node;
		return ;
	}
	stack->top = node;
	stack->bottom = node;
}

void	stack_push_front(t_stack *stack, t_node *node)
{
	if (!stack)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
		return ;
	}
	node->next = stack->top;
	stack->top = node;
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*temp;

	size = 0;
	if (!stack || !stack->top)
		return (size);
	temp = stack->top;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
