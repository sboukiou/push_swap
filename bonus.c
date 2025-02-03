/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:52:57 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/03 10:23:03 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	quit(t_stack *stack_a, t_stack *stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
	write(STDOUT_FILENO,"Error\n", 6);
	exit(0);
}

static int	move_isvalide(char *move)
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

static void	apply_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!move)
		return ;
	if (!ft_strncmp(move, "rra\n", 4))
		rrab(stack_a, NULL);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrab(stack_a, NULL);
	else if (!ft_strncmp(move, "ra\n", 3))
		rab(stack_a, NULL);
	else if (!ft_strncmp(move, "rb\n", 3))
		rab(stack_a, NULL);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (rrab(stack_a, NULL), rrab(stack_a, NULL));
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (rab(stack_a,NULL), rab(stack_a,NULL));
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


void	apply_moves(t_stack *stack_a, t_stack *stack_b, int fd)
{
	char	move[4];
	char	byte;
	int		bytes_read;
	int		idx;

	if (fd < 0 || fd > 1024)
		return ;
	bytes_read = read(fd, &byte, 1);
	while (bytes_read)
	{
		idx = 0;
		while (bytes_read)
		{
			move[idx] = byte;
			idx++;
			if (idx == 4)
			{
				move[idx] = '\0';
				idx = 0;
			}
			bytes_read = read(fd, &byte, 1);
		}
		if (!move_isvalide(move))
			quit(stack_a, stack_b);
		apply_move(stack_a, stack_b, move);
	}
}

void stack_print(t_stack *stack)
{
	t_node *temp;

	if (!stack)
		return ;
	temp = stack->top;
	while (temp)
	{
		printf(" %d -> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = parser(av);
	stack_b = stack_new(NULL, NULL);
	if (!stack_a || !stack_b)
		return (0);
	apply_moves(stack_a, stack_b, STDIN_FILENO);
	stack_print(stack_a);
	if (stack_issorted(stack_a))
	 write(STDOUT_FILENO, "OK\n", 3);
	else
	 write(STDOUT_FILENO, "KO\n", 3);
	stack_free(stack_a);
	stack_free(stack_b);
}
