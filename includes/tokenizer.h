#ifndef	TOKENIZER_H
#define	TOKENIZER_H

#include "./common.h"
t_stack	*tokenize_input(char **input);
void	sorter(t_stack *stack_a, t_stack *stack_b);
#endif
