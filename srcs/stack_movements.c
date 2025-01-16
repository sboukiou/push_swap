#include "../includes/common.h"
/*#include "../includes/libft.h"*/
#include "../includes/push_swap.h"

void	sab(t_stack	*stack)
{
	if (stack->top && stack->top->next)
		stack_swap(stack->top, stack->top->next);
}

void	pab(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || !b || !a->top)
		return ;
	temp = a->top;
	stack_remove(a, a->top);
	stack_push_front(b, temp);
}
void	rab(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	stack_remove(stack, temp);
	stack_push_back(stack, temp);
}

void	rrab(t_stack *stack)
{
	(void)stack;
}
