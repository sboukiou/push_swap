#include "../includes/push_swap.h"
#include <stdio.h>


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

void	stack_remove(t_stack *stack, t_node *node)
{
	t_node	*temp;
	t_node	*to_remove;
	if (!stack || !node || !stack->top)
		return ;
	if (stack->top == node)
	{
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

int	stack_index_of(t_stack *stack, int value)
{
	t_node	*temp;
	int	index;

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

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*temp;

	temp = stack->top;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	stack_checkdup(t_stack *stack, int value)
{
	t_node	*temp;
	int	count;
	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	count = 0;
	while (temp)
	{
		if (temp->value == value)
			count++;
		temp = temp->next;
	}
	return (count);
}
