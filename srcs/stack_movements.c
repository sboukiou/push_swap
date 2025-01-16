#include "../includes/push_swap.h"


void	sab(int	*stack, size_t size)
{
	int	temp;
	(void)size;
	if (!stack)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}
