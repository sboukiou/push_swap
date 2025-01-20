#include "../includes/push_swap.h"


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	/*t_node	*temp;*/
	if(ac < 2)
		return (0);
	error_check(av);
	stack_a = tokenize_input(av);
	stack_duplicate(stack_a);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		printf("Nothing returned from tokenizer, Leaving ...\n"), exit(0);

	stack_b->top = NULL;
	stack_b->bottom = NULL;
	/*----------------------------------------------------*/
	/*printf("Stack initialized\n-------------\n");*/
	/*stack_print(stack_a);*/
	/*----------------------------------------------------*/

	/* rra works fine so far */
	/*----------------------------------------------------*/
	/*printf("aplying rra ...\n-------------\n");*/
	/*stack_print(stack_a);*/
	sorter(stack_a, stack_b);

	/*----------------------------------------------------*/

	/*----------------------------------------------------*/
	/*printf("Stack sorted\n-------------\n");*/
	/*stack_print(stack_a);*/

	/*----------------------------------------------------*/
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);

}
