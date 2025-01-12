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
	stack_push_back(b, a->top);
	a->top = a->top->next;
	b->bottom->next = NULL;
}

void	rab(t_stack *stack)
{
	t_node	*temp_top;

	temp_top = stack->top;
	stack->top = temp_top->next;
	stack->top->prev = NULL;
	stack->bottom->next = temp_top;
	temp_top->next = NULL;
	stack->bottom = temp_top;
}

void	rrab(t_stack *stack)
{
	t_node	*temp_top;
	t_node	*temp_bot;

	temp_top = stack->top;
	temp_bot = stack->bottom;
	stack->top = temp_bot;
	stack->bottom = temp_bot->prev;
	stack->bottom->next = NULL;
	temp_bot->next = temp_top;
	temp_top->next->prev = temp_bot;
	
}
