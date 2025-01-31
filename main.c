#include "./push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = stack_new(NULL, NULL);
	stack_a = parser(av);
	t_node	*temp = stack_a->top;
	while (temp)
	{
		printf(" %d --> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	if (!stack_a || !stack_b)
		return (0);
}
