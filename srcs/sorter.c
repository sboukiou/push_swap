#include "../includes/common.h"
#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ref;

	ref = stack_duplicate(stack);
	if (!ref)
		return (-12);
	stack_sort(ref);
	while (ref->top)
	{
		if (ref->top->value != stack->top->value)
		{
			stack_free(ref);
			return (0);
		}
		ref->top = ref->top->next;
	}
	stack_free(ref);
	return (1);
}

void	sorter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*ref;
	t_node	*temp;
	int	size;

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);
	temp = ref->top;
	size = stack_size(stack_a);

	while (temp)
	{
		while (stack_a->top && stack_a->top->value != temp->value)
		{
			if (stack_index_of(stack_a, temp->value) < size / 2)
				while (stack_a->top && stack_a->top->next && stack_a->top->value != temp->value)
				{
					printf("ra\n");
					rab(stack_a);
				}
			else
				while (stack_a->top && stack_a->top->next && stack_a->top->value != temp->value)
				{
					printf("rra\n");
					rrab(stack_a);
				}
		}
		printf("pb\n");
		pab(stack_a, stack_b);
		temp = temp->next;
	}


	while (stack_b->top)
	{
		pab(stack_b, stack_a);
		printf("pa\n");
	}
	stack_free(ref);
}
