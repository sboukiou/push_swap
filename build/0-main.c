#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include <stdio.h>

#define TOP 0

int main(int ac, char **av)
{
	(void)ac;
	int		*stack_a;
	int		*stack_b;
	size_t	size;

	size = count_elements(av);
	stack_a = split_input(av, ac);
	if (!stack_a)
		return (0);
	stack_b = stack_duplicate(stack_a, size);
	if (!stack_b)
		return (free(stack_a),0);

	stack_print(stack_a, size);
	sab(stack_a, size);
	printf("after sa\n");
	stack_print(stack_a, size);

	free(stack_a);
	free(stack_b);
	return (0);

}
