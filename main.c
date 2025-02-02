#include "./push_swap.h"

void stack_print(t_stack *stack)
{
	t_node *temp;
	if (!stack)
		return ;
	temp = stack->top;
	while (temp)
	{
		printf(" %d -> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

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
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
