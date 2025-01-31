#include "./push_swap.h"

static void	list_free(char **list)
{
	int idx;

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

t_stack	*parser(char **av)
{
	int		idx;
	int		jdx;
	int		temp;
	char	**list;
	t_stack	*stack;

	idx = 1;
	stack = stack_new(NULL, NULL);
	while (av[idx])
	{
		list = ft_split(av[idx], ' ');
		jdx = 0;
		while (list[jdx])
		{
			temp =  ft_atoi(list[jdx]);
			if ((temp == -1 && ft_strncmp(list[jdx], "-1", 2)) || deja_vue(stack, temp))
				quit(stack, list);
			stack_push_back(stack, new_node(temp));
			jdx++;
		}
		list_free(list);
		idx++;
	}
	return (stack);
}
