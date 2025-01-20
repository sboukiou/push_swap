#include "../includes/push_swap.h"
#include <stdio.h>


int main(int ac, char **av)
{
	t_stack	*stack;
	/*t_node	*temp;*/
	if(ac < 2)
		return (0);
	error_check(av);
	stack = tokenize_input(av);
	if (!stack)
		printf("Nothing returned from tokenizer, Leaving ...\n");
	stack_print(stack);
	rrab(stack);
	stack_print(stack);
	rrab(stack);
	rrab(stack);
	printf("after second rrab\n");
	stack_print(stack);
	stack_free(stack);
	return (0);

}
