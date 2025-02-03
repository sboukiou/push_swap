/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:42:51 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/03 15:46:43 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	move_isvalide(char *move)
{
	if (!move)
		return (0);
	if (!ft_strncmp(move, "rra\n", 4))
		return (1);
	if (!ft_strncmp(move, "rrb\n", 4))
		return (1);
	if (!ft_strncmp(move, "ra\n", 3))
		return (1);
	if (!ft_strncmp(move, "rb\n", 3))
		return (1);
	if (!ft_strncmp(move, "rr\n", 3))
		return (1);
	if (!ft_strncmp(move, "rrr\n", 4))
		return (1);
	if (!ft_strncmp(move, "sa\n", 3))
		return (1);
	if (!ft_strncmp(move, "ss\n", 3))
		return (1);
	if (!ft_strncmp(move, "sb\n", 3))
		return (1);
	if (!ft_strncmp(move, "pa\n", 3))
		return (1);
	if (!ft_strncmp(move, "pb\n", 3))
		return (1);
	return (0);
}

void	quit(t_stack *stack_a, t_stack *stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
	write(STDOUT_FILENO, "Error\n", 6);
	exit(0);
}

void	apply_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!move)
		return ;
	if (!ft_strncmp(move, "rra\n", 4))
		rrab(stack_a, NULL);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrab(stack_b, NULL);
	else if (!ft_strncmp(move, "ra\n", 3))
		rab(stack_a, NULL);
	else if (!ft_strncmp(move, "rb\n", 3))
		rab(stack_b, NULL);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (rab(stack_b, NULL), rab(stack_a, NULL));
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (rrab(stack_b, NULL), rrab(stack_a, NULL));
	else if (!ft_strncmp(move, "sa\n", 3))
		sab(stack_a, NULL);
	else if (!ft_strncmp(move, "sb\n", 3))
		sab(stack_b, NULL);
	else if (!ft_strncmp(move, "ss\n", 3))
		return (sab(stack_a, NULL), sab(stack_b, NULL));
	else if (!ft_strncmp(move, "pa\n", 3))
		pab(stack_b, stack_a, NULL);
	else if (!ft_strncmp(move, "pb\n", 3))
		pab(stack_a, stack_b, NULL);
}

