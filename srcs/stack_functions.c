#include "../includes/push_swap.h"

int	*stack_duplicate(int *stack, size_t size)
{
	int		*new_stack;
	size_t	idx;

	if (!stack || size == 0)
		return (NULL);
	new_stack = (int *)malloc(sizeof(int) * (size + 1));
	if (!new_stack)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		new_stack[idx] = stack[idx];
		idx++;
	}
	return (new_stack);
}


void	stack_print(int *stack, size_t size)
{
	size_t	idx;

	if (!stack)
		return ;
	idx = 0;
	printf("|");
	while (idx < size)
	{
		printf(" %d", stack[idx]);
		idx++;
	}
	printf(" |");
}
