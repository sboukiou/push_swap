#include "./push_swap.h"

void	sorter(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_issorted(stack_a))
		return ;
	if (stack_size(stack_a) == 2)
		return (sab(stack_a, "sa\n"));
	if (stack_size(stack_a) == 3)
		return (sort_size_three(stack_a));
	if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		return (sort_size_four_five(stack_a, stack_b));
	write(STDOUT_FILENO, "Size is above 5\n", 17);
}
