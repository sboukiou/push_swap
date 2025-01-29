/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs_adv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:00 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 17:19:14 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_swap(t_node *node_a, t_node *node_b)
{
	int	temp;

	temp = node_a->value;
	node_a->value = node_b->value;
	node_b->value = temp;
}

void	stack_sort(t_stack *stack)
{
	/*bubble sort implementation*/
	/*Insertion sort removed*/
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

t_stack	*stack_duplicate(t_stack *stack)
{
	t_stack	*new_stack;
	t_node			*temp;
	t_node			*copy;


	if (!stack)
		return (NULL);
	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	temp =  stack->top;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	while (temp)
	{
		copy = stack_create_node(temp->value);
		if (!copy)
			return (stack_free(new_stack), NULL);
		stack_push_back(new_stack, copy);
		temp = temp->next;
	}
	return (new_stack);
}
