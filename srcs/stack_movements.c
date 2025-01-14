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
	t_node	*temp_top;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	temp_top = stack->top;
	stack->top = temp_top->next;
	stack->top->prev = NULL;
	stack->bottom->next = temp_top;
	temp_top->next = NULL;
	stack->bottom = temp_top;
}

void	rrab(t_stack *stack)
{
	t_node	*temp_bot;

	if (!stack || !stack->bottom || !stack->top)
		return ;
	if (!(stack->top->next) || !stack->bottom->prev)
		return ;
	temp_bot = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;

	stack->top->prev = temp_bot;
	temp_bot->next = stack->top;
	temp_bot->prev = NULL;
	stack->top = temp_bot;
}
