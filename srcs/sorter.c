#include "../includes/common.h"
#include "../includes/push_swap.h"

void	sort_size_three(t_stack *stack_a)
{
	t_node	*temp;

	temp = stack_a->top;

	if (temp->value < temp->next->value && temp->value < stack_a->bottom->value)
		return (printf("rra\n"), printf("sa\n"), rrab(stack_a), sab(stack_a));
	if (temp->value > temp->next->value && temp->value < stack_a->bottom->value)
		return (printf("sa\n"), sab(stack_a));
	if (temp->value < temp->next->value && temp->value > stack_a->bottom->value)
		return (printf("rra\n"), rrab(stack_a));
	if (temp->value > temp->next->value && temp->value > stack_a->bottom->value)
	{
		temp = temp->next;
		if (temp->value > temp->next->value)
		{
			printf("sa\n");
			sab(stack_a);
			return (printf("rra\n"), rrab(stack_a));
		}
		if (temp->value < temp->next->value)
		{
			printf("rra\n");
			rrab(stack_a);
			return (printf("rra\n"), rrab(stack_a));
		}
	}
}

void	sort_size_four_five(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*ref;

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);

	find_and_push(stack_a, stack_b, ref->top->value);
	if (stack_size(stack_a) == 4)
		find_and_push(stack_a, stack_b, ref->top->next->value);
	sort_size_three(stack_a);
	pab(stack_b, stack_a);
	pab(stack_b, stack_a);
	printf("pa\n");
	printf("pa\n");
}

void	sorter(t_stack *stack_a, t_stack *stack_b)
{

	if (stack_size(stack_a) == 3)
		return (sort_size_three(stack_a));
	if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		return (sort_size_four_five(stack_a, stack_b));
	/*Implement the new logic here*/
}
