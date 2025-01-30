/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:12:31 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:13:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = stack_init(av);
	if (is_sorted(stack_a))
		return (stack_free(stack_a), 0);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
	{
		stack_free(stack_a);
		return (0);
	}
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	sorter(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
