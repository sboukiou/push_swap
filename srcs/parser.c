/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:26:14 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:37:02 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	quit(void)
{
	write(STDOUT_FILENO, "Error\n", 6);
	exit(0);
}

static int	deja_vue(t_stack *stack, int value)
{
	int		count;
	t_node	*temp;

	if (!stack || !stack->top)
		return (0);
	count = 0;
	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			count++;
		temp = temp->next;
	}
	if (count > 1)
		return (1);
	return (0);
}

void	fetch_and_push(t_stack *stack_a, char **list)
{
	int	jdx;
	int	temp;

	jdx = 0;
	while (list[jdx])
	{
		temp = ft_atoi(list[jdx]);
		if ((temp == -1 && ft_strcmp(list[jdx], "-1"))
			|| deja_vue(stack_a, temp))
		{
			ft_double_free(list);
			stack_free(stack_a);
			quit();
		}
		stack_push_back(stack_a, stack_create_node(temp));
		jdx++;
	}
}

t_stack	*stack_init(char **args)
{
	int		idx;
	char	**list;
	t_stack	*stack_a;

	idx = 1;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	if (!stack_a)
		quit();
	while (args[idx])
	{
		list = ft_split(args[idx], ' ');
		if (!list)
		{
			stack_free(stack_a);
			quit();
		}
		fetch_and_push(stack_a, list);
		idx++;
	}
	return (stack_a);
}
