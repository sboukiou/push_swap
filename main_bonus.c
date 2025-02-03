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
		rrab(stack_b, NULL);
	else if (!ft_strncmp(move, "ra\n", 3))
		rab(stack_a, NULL);
	else if (!ft_strncmp(move, "rb\n", 3))
		rab(stack_b, NULL);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (rab(stack_b, NULL), rab(stack_a, NULL));
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (rrab(stack_b,NULL), rrab(stack_a,NULL));
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

static char	*get_line(int fd)
{
	char	(*line), (byte);
	int		(idx), (byte_read);

	if (fd < 0 || fd > 1024)
		return (NULL);
	idx = 0;
	byte_read = read(fd, &byte, 1);
	line = ft_calloc(5, sizeof(char));
	if (!line)
		return (NULL);
	idx = 0;
	while (byte_read > 0)
	{
		line[idx] = byte;
		if (byte == '\n' || idx == 4)
			return (line);
		idx++;
		byte_read = read(fd, &byte, 1);
	}
	return (line);
}


void	apply_moves(t_stack *stack_a, t_stack *stack_b, int fd)
{
	char	(*move);

	move = get_line(fd);
	while (move)
	{
		if (!move)
			quit(stack_a, stack_b);
		if (!move[0])
		{
			free(move);
			return ;
		}
		if (!move_isvalide(move))
			quit(stack_a, stack_b);
		apply_move(stack_a, stack_b, move);
		free(move);
		move = get_line(fd);
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
	if (stack_issorted(stack_a))
	 write(STDOUT_FILENO, "OK\n", 3);
	else
	 write(STDOUT_FILENO, "KO\n", 3);
	stack_free(stack_a);
	stack_free(stack_b);
}
