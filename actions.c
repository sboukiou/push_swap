/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:10:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:10:49 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	if (stack->top && stack->top->next)
		stack_swap(stack->top, stack->top->next);
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
