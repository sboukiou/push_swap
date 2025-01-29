#include "../includes/push_swap.h"


void	find_and_push(t_stack *stack_a, t_stack *stack_b, int value)
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
				printf("ra\n"), rab(stack_a);
		}
		else
		{
			while (stack_a->top->value != value)
				printf("rra\n"), rrab(stack_a);
		}
	}
	pab(stack_a, stack_b);
	printf("pb\n");
}
