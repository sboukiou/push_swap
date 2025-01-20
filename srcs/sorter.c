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
	(void)stack_a;
	(void)stack_b;
	t_stack	*ref;
	t_node	*temp;

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);
	temp = ref->top;
	while (temp)
	{
		while (stack_a->top->value != temp->value)
		{
			printf("rra\n");
			rrab(stack_a);
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
