#ifndef LISTS_H
#define LISTS_H

#include "./common.h"

t_node	*stack_create_node(int value);
void	stack_push_back(t_stack *stack, t_node *node);
void	stack_push_front(t_stack *stack, t_node *node);
#endif
