#include "../includes/push_swap.h"
#include <stdio.h>


int main(int ac, char **av)
{
	t_node	*numbers;
	t_node	*temp;
	if(ac < 2)
	{
		printf("Arguments needed\n");
		return (0);
	}
	numbers = tokenize_input(av);
	if (!numbers)
		printf("Nothing returned from tokenizer, Leaving ...\n");
	stack_print(numbers);
	stack_free(&numbers);
	return (0);

}
