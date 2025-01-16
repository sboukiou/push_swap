#include "../includes/push_swap.h"
#include <stdio.h>


int main(int ac, char **av)
{
	t_stack	*numbers;
	/*t_node	*temp;*/
	if(ac < 2)
		return (0);
	error_check(av);
	numbers = tokenize_input(av);
	if (!numbers)
		printf("Nothing returned from tokenizer, Leaving ...\n");
	stack_print(numbers);
	stack_free(numbers);
	return (0);

}
