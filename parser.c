/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:24:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/03 17:32:43 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	list_free(char **list)
{
	int	idx;

	if (!list)
		return ;
	idx = 0;
	while (list[idx])
	{
		free(list[idx]);
		idx++;
	}
	free(list);
}

static int	deja_vue(t_stack *stack, int value)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	quit(t_stack *stack, char **list)
{
	list_free(list);
	stack_free(stack);
	write(STDOUT_FILENO, "Error\n", 6);
	exit(0);
}

void	check_one_num(char *num, char **list, t_stack *stack)
{
	int	temp;

	temp = ft_atoi(num);
	if ((temp == -1 && ft_strcmp(num, "-1"))
		|| deja_vue(stack, temp))
		quit(stack, list);
	stack_push_back(stack, new_node(temp));
}

t_stack	*parser(char **av)
{
	char	**list;
	t_stack	*stack;
	int		idx;
	int		jdx;

	idx = 1;
	stack = stack_new(NULL, NULL);
	while (av[idx])
	{
		if (!ft_strlen(av[idx]))
			quit(stack, NULL);
		list = ft_split(av[idx], ' ');
		jdx = 0;
		if (!list[jdx] || !ft_strlen(list[jdx]))
			quit(stack, list);
		while (list[jdx])
		{
			check_one_num(list[jdx], list, stack);
			jdx++;
		}
		list_free(list);
		idx++;
	}
	return (stack);
}
