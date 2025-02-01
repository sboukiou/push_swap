#include "./push_swap.h"


void	pab(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_node	*temp;

	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	if (!stack_a || !stack_b || !stack_a->top)
		return ;
	temp = stack_a->top;
	stack_remove(stack_a, stack_a->top);
	stack_push_front(stack_b, temp);
}

void	sab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->top;
	stack->top = temp->next;
	stack->top->next = temp;
}

void	rab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->top;
	stack_remove(stack, temp);
	stack_push_back(stack, temp);
}

void	rrab(t_stack *stack, char *str)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	temp = stack->bottom;
	stack_remove(stack, temp);
	stack_push_front(stack, temp);
}
