#include "../includes/push_swap.h"

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

t_node	*stack_find_prev(t_stack *stack, int value)
{
	t_node	*temp;
	if (!stack)
		return (NULL);
	temp = stack->top;
	while (temp)
	{
		if (temp->value < value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
t_node	*stack_smallest(t_stack *stack)
{
	t_node	*temp;
	t_node	*placeholder;

	if (!stack)
		return (NULL);
	temp = stack->top;
	placeholder = stack->top;
	while (temp)
	{
		if (temp->value < placeholder->value)
			placeholder = temp;
		temp = temp->next;
	}
	return (placeholder);
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
