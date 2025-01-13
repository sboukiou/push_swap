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

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);
	temp = ref->top;
	while (!is_sorted(stack_a) && stack_b->top == NULL)
	{
		while (stack_a->top)
		{
			if (stack_a->top->next && stack_a->top->value > stack_a->top->next->value)
			{
				printf("sa\n");
				sab(stack_a);
			}
			pab(stack_a, stack_b);
			if (stack_b->top->next && stack_b->top->value < stack_b->top->next->value)
			{
				printf("sb\n");
				sab(stack_b);
			}
		}
		while (stack_b->top)
		{
			if (stack_b->top->next && stack_b->top->value < stack_a->top->next->value)
			{
				printf("sb\n");
				sab(stack_b);
			}
			if (stack_a->top->next && stack_a->top->value > stack_b->top->next->value)
			{
				printf("sa\n");
				sab(stack_a);
			}
		}
	}
	/*while (stack_b->top)*/
	/*{*/
	/*	pab(stack_b, stack_a);*/
	/*	printf("pa\n");*/
	/*}*/
	/*printf("stack_b sorted -->\n");*/
	/*stack_print(stack_b);*/
	/*printf("stack_a sorted -->\n");*/
	/*stack_print(stack_a);*/
	stack_free(ref);
}
