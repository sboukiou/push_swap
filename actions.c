#include "./push_swap.h"


void	pab(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_node	*temp;

	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	if (!stack_a || !stack_b || !stack_a->top)
		return ;
	temp = stack_a->top;
	stack_remove(stack_a, stack_a->top);
	stack_push_front(stack_b, temp);
}

void	sab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->top;
	stack->top = temp->next;
	stack->top->next = temp;
}

void	rab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->top;
	stack_remove(stack, temp);
	stack_push_back(stack, temp);
}

void	rrab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->bottom;
	stack_remove(stack, temp);
	stack_push_front(stack, temp);
}

void	find_and_push_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	size_t	size_a;
	size_t	index;

	if (!stack_a || !stack_b)
		return ;
	size_a = stack_size(stack_a);
	index = stack_index_of(stack_a, value);
	while (stack_a->top->value != value)
	{
		if (size_a / 2 > index)
		{
			while (stack_a->top->value != value)
				rab(stack_a, "ra\n");
		}
		else
		{
			while (stack_a->top->value != value)
				rrab(stack_a, "rra\n");
		}
	}
	pab(stack_a, stack_b, "pb\n");
}

void	find_and_push_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	size_t	size_a;
	size_t	index;

	if (!stack_b || !stack_a)
		return ;
	size_a = stack_size(stack_b);
	index = stack_index_of(stack_b, value);
	while (stack_b->top->value != value)
	{
		if (size_a / 2 > index)
		{
			while (stack_b->top->value != value)
				rab(stack_b, "rb\n");
		}
		else
		{
			while (stack_b->top->value != value)
				rrab(stack_b, "rrb\n");
		}
	}
	pab(stack_b, stack_a, "pa\n");
}
