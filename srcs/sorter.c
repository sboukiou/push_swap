#include "../includes/common.h"
#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ref;
	t_node	*temp_ref;
	t_node	*temp_stack;

	ref = stack_duplicate(stack);
	if (!ref)
		return (0);
	stack_sort(ref);
	temp_ref = ref->top;
	temp_stack = stack->top;
	while (temp_ref)
	{
		if (temp_ref->value != temp_stack->value)
		{
			stack_free(ref);
			return (0);
		}
		temp_ref = temp_ref->next;
		temp_stack = temp_stack->next;
	}
	stack_free(ref);
	return (1);
}

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

void	insertion_sort(t_stack *stack_a, t_stack *stack_b);
void	sorter(t_stack *stack_a, t_stack *stack_b)
{

	if (stack_size(stack_a) == 3)
		return (sort_size_three(stack_a));
	if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		return (sort_size_four_five(stack_a, stack_b));
	insertion_sort(stack_a, stack_b);
	/*stack_print(stack_a);*/
	/*ref = stack_duplicate(stack_a);*/
	/*stack_sort(ref);*/
	/*temp = ref->top;*/
	/*while (temp)*/
	/*{*/
	/*	find_and_push(stack_a, stack_b, temp->value);*/
	/*	temp = temp->next;*/
	/*}*/
	/**/
	/*while (stack_b->top)*/
	/*{*/
	/*	pab(stack_b, stack_a);*/
	/*	printf("pa\n");*/
	/*}*/
	/*stack_free(ref);*/
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;
	t_stack	*ref;

	if (!stack_a || !stack_b)
		return ;
	ref = stack_duplicate(stack_a);
	stack_sort(ref);
	while (stack_size(stack_a) > 0)
	{
		/*printf("Inloop\n");*/
		if (stack_a->top->next && stack_a->top->value > stack_a->top->next->value && stack_size(stack_b) > 1 && stack_b->top->value  < stack_b->top->next->value)
			printf("ss\n"), sab(stack_a), sab(stack_b);
		else if (stack_a->top->next && stack_a->top->value > stack_a->top->next->value)
			printf("sa\n"), sab(stack_a);
		else if (stack_b->top->next && stack_b->top->value < stack_b->top->next->value)
			printf("sb\n"), sab(stack_b);
		printf("pb\n"), pab(stack_a, stack_b);
		if (stack_size(stack_b) > 1)
		{
			if (stack_b->top->value == ref->top->value)
				printf("rb\n"), rab(stack_a);
			temp = stack_find_prev(stack_b, stack_b->top->value);
			if (!temp)
				printf("rb\n"), rab(stack_b);
			else if (stack_b->top->value < stack_b->top->next->value)
			{
				while (stack_b->top->value != temp->value)
					printf("rrb\n"), rrab(stack_b);
				printf("sb\n"), sab(stack_b);
				temp = stack_smallest(stack_b);
				while (stack_b->bottom->value != temp->value)
					printf("rb\n"), rab(stack_b);
			}
		}
		/*stack_print(stack_b);*/
	}
	while (stack_size(stack_b) > 0)
		printf("pa\n"), pab(stack_b, stack_a);
	stack_free(ref);
}
