#include "../includes/push_swap.h"

static void	quit(void)
{
	printf("Error\n");
	exit(0);
}

static void	error_duplicate(t_stack *stack, int value)
{
	t_node	*temp;
	int		count;

	if (!stack || !stack->top)
		return ;
	count = 0;
	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			count++;
		temp = temp->next;
	}
	if (count > 1)
		quit();
}

void	error_stack_dup(t_stack *stack)
{
	t_node	*temp;
	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	while (temp)
	{
		error_duplicate(stack, temp->value);
		temp = temp->next;
	}
	return ;
}

static int	error_notnumber(char *str)
{
	int	num;

	if (!str)
		return -1;
	num = ft_atoi(str);
	if (num == 0)
	{
		if (ft_strcmp(str,"0") && ft_strcmp(str,"-0") && ft_strcmp(str,"-0"))
			return (-1);
	}
	if (num == -1 && ft_strcmp(str, "-1"))
			return (-1);
	return (0);
}

void	error_check(char **av)
{
	int	idx;
	int	jdx;
	char **list;

	idx = 1;
	while (av[idx])
	{
		list = ft_split(av[idx], ' ');
		jdx = 0;
		while (list[jdx])
			error_notnumber(list[jdx++]);
		ft_double_free(list);
		idx++;
	}
}

