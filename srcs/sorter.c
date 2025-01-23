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

void	sort_size_five(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*ref;

	ref = stack_duplicate(stack_a);
	if (!ref)
		return ;
	stack_sort(ref);

	while (stack_a->top->value != ref->top->value)
	{
		if (stack_index_of(stack_a, ref->top->value) > stack_size(stack_a) / 2)
		{
			while (stack_a->top->value != ref->top->value)
			{
				printf("rra\n");
				rrab(stack_a);
			}
		}
		else
		{
			while (stack_a->top->value != ref->top->value)
			{
				printf("ra\n");
				rab(stack_a);
			}
		}
	}
	printf("pb\n");
	pab(stack_a, stack_b);
	if (stack_size(stack_a) == 4)
	{
		while (stack_a->top->value != ref->top->next->value)
		{
			if (stack_index_of(stack_a, ref->top->next->value) > stack_size(stack_a) / 2)
			{
				while (stack_a->top->value != ref->top->next->value)
				{
					printf("rra\n");
					rrab(stack_a);
				}
			}
			else
			{
				while (stack_a->top->value != ref->top->next->value)
				{
					printf("ra\n");
					rab(stack_a);
				}
			}
		}
		printf("pb\n");
		pab(stack_a, stack_b);
	}
	sort_size_three(stack_a);
	pab(stack_b, stack_a);
	pab(stack_b, stack_a);
	printf("pa\n");
	printf("pa\n");
}

void	sorter(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	t_stack	*ref;
	t_node	*temp;

	if (stack_size(stack_a) == 3)
		return (sort_size_three(stack_a));
	if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		return (sort_size_five(stack_a, stack_b));
	ref = stack_duplicate(stack_a);
	stack_sort(ref);
	temp = ref->top;
	while (temp)
	{
		if (stack_index_of(stack_a, temp->value) > stack_size(stack_a) / 2)
		{
			while (stack_a->top->value != temp->value)
			{
				printf("rra\n");
				rrab(stack_a);
			}
		}
		else
		{
			while (stack_a->top->value != temp->value)
			{
				printf("ra\n");
				rab(stack_a);
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
