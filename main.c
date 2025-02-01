#include "./push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)ac;
	stack_b = stack_new(NULL, NULL);
	stack_a = parser(av);
	if (!stack_a || !stack_b)
		return (0);
	t_node	*temp = stack_a->top;
	/*sorter(stack_a, stack_b);*/
}
