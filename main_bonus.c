/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:52:57 by sboukiou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/03 15:51:45 by sboukiou         ###   ########.fr       */
=======
/*   Updated: 2025/02/03 16:25:47 by sboukiou         ###   ########.fr       */
>>>>>>> parsing
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./push_swap_bonus.h"

static char	*get_line(int fd)
{
	char	*line;
	char	byte;
	int		idx;
	int		byte_read;

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
		if (idx < 4)
			line[idx] = byte;
		if (byte == '\n')
			return (line);
		idx++;
		byte_read = read(fd, &byte, 1);
	}
	return (line);
}

void	apply_moves(t_stack *stack_a, t_stack *stack_b, int fd)
{
	char	*move;

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
			return (free(move), quit(stack_a, stack_b));
		apply_move(stack_a, stack_b, move);
		free(move);
		move = get_line(fd);
	}
}

int	main(int ac, char **av)
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
	if (stack_issorted(stack_a) && !stack_b->top)
	 write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	stack_free(stack_a);
	stack_free(stack_b);
}
