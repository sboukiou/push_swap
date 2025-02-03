/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:08:46 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:31:08 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	*init_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	*ref;

	if (stack_issorted(stack_a))
		return (NULL);
	if (stack_size(stack_a) == 2)
		return (sab(stack_a, "sa\n"), NULL);
	if (stack_size(stack_a) == 3)
		return (sort_size_three(stack_a), NULL);
	if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		return (sort_size_four_five(stack_a, stack_b), NULL);
	ref = create_ref_array(stack_a);
	return (ref);
}

static void	found_start(t_stack *stack_a,
						t_stack *stack_b, int *start, int *end)
{
	pab(stack_a, stack_b, "pb\n");
	rab(stack_b, "rb\n");
	(*end)++;
	(*start)++;
}

static void	found_end(t_stack *stack_a, t_stack *stack_b, int *start, int *end)
{
	pab(stack_a, stack_b, "pb\n");
	if (stack_b->top->next && stack_b->top->next->value > stack_b->top->value)
		sab(stack_b, "sb\n");
	(*end)++;
	(*start)++;
}

void	sorter(t_stack *stack_a, t_stack *stack_b)
{
	int	*ref;
	int	start;
	int	end;
	int	size;

	ref = init_algo(stack_a, stack_b);
	if (ref == NULL)
		return ;
	size = stack_size(stack_a);
	start = 0;
	end = size / 6;
	if (size > 100)
		end = size / 14;
	while (stack_a->top)
	{
		if (includes(ref, stack_a->top->value, start))
			found_start(stack_a, stack_b, &start, &end);
		else if (includes(ref, stack_a->top->value, end))
			found_end(stack_a, stack_b, &start, &end);
		else
			rab(stack_a, "ra\n");
	}
	while (stack_b->top)
		find_and_push_b(stack_a, stack_b, ref[--size]);
}
