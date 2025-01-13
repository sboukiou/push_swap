#include "../includes/push_swap.h"
#include <stdio.h>


t_node	*stack_create_node(int value, t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = prev;
	return (new_node);
}

t_stack	*stack_push_back(t_stack *stack_data, t_node	*node)
{
	t_node	*temp;

	if (!stack_data || !node)
		return (NULL);
	if (!stack_data->top)
	{
		stack_data->top = node;
		stack_data->bottom = node;
		stack_data->top->next = NULL;
		return (stack_data);
	}
	if (stack_data->bottom)
		stack_data->bottom->next = node;
	stack_data->bottom = node;
	stack_data->bottom->next = NULL;
	return (stack_data);
}

t_stack	*stack_push_front(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (!stack || !node)
		return (NULL);
	if (!stack->top)
		return (stack_push_back(stack, node));
	temp = stack->top;
	node->next = temp;
	node->prev = NULL;
	stack->top->prev = node;
	stack->top = node;
	return (stack);
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
	stack_data = NULL;
}

void	stack_print(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return  ;
	temp = stack->top;
	printf("stack -----------\n");
	while (temp)
	{
		printf("| %d |\n", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("-----------\n");
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
	t_node	*saved;
	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	int	temp_val;
	while (temp)
	{
		saved = temp;
		while (saved->prev && saved->value < saved->prev->value)
		{
			stack_swap(saved, saved->prev);
			saved = saved->prev;
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
		copy = stack_create_node(temp->value, new_stack->bottom);
		if (!copy)
			return (stack_free(new_stack), NULL);
		stack_push_back(new_stack, copy);
		temp = temp->next;
	}
	return (new_stack);
}

void	stack_remove(t_stack *stack, t_node *node)
{
	t_node	*temp_prev;
	t_node	*temp_next;


	if (!stack || !node)
		return ;
	if (!node->prev && !node->next)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		return ;
	}
	if (stack->top == node)
	{
		stack->top = node->next;
		stack->top->prev = NULL;
		return ;
	}
	if (stack->bottom == node)
	{
		stack->bottom = node->prev;
		stack->bottom->next = NULL;
		return ;
	}
	temp_prev = node->prev;
	temp_next = node->next;
	temp_prev->next = temp_next;
	temp_next->prev = temp_prev;
}
