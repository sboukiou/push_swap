#include "../includes/push_swap.h"
#include <stdio.h>


int main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stack_b;
	/*t_node	*temp;*/
	if(ac < 2)
		return (0);
	error_check(av);
	stack = tokenize_input(av);
	if (!stack)
		printf("Nothing returned from tokenizer, Leaving ...\n");
	error_stack_dup(stack);
	/*stack_print(stack);*/
	/*rrab(stack);*/
	/*rrab(stack);*/
	/*printf("after second rrab\n");*/
	/*stack_print(stack);*/
	/*printf("After sorting the stack\n");*/
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	/*stack_sort(stack);*/
	sorter(stack, stack_b);
	/*stack_print(stack);*/
	stack_free(stack);
	return (0);

}
