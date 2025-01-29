/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:16:59 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 17:17:11 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*stack_create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	stack_push_back(t_stack *stack, t_node	*node)
{
	if (!stack || !node)
		return ;
	node->next = NULL;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
		return ;
	}
	stack->bottom->next = node;
	stack->bottom = node;
}

void	stack_push_front(t_stack *stack, t_node *node)
{

	if (!stack || !node)
		return ;
	if (!stack->top)
		return (stack_push_back(stack, node));
	node->next = stack->top;
	stack->top = node;
}

void	stack_free(t_stack *stack_data)
{
	t_node	*temp;
	t_node	*to_free;

	if (!stack_data)
		return ;
	temp = stack_data->top;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	free(stack_data);
}

void	stack_print(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return  ;
	temp = stack->top;
	printf("\nstack -----------\n");
	while (temp)
	{
		printf(" %d ->", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("-----------\n");
}
