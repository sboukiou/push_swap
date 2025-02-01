#include "./push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)ac;
	stack_a = parser(av);
	stack_b = stack_new(NULL, NULL);
	if (!stack_a || !stack_b)
		return (0);
	sorter(stack_a, stack_b);
	printf("freeing before\n");
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
