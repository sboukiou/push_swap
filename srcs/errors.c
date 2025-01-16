#include "../includes/push_swap.h"

static void	quit(char *str)
{
	/*if (str)*/
	/*	printf("%s\n", str);*/
	(void)str;
	printf("Error\n");
	exit(0);
}

void	error_duplicate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	while (temp)
	{
		if (stack_checkdup(stack, temp->value) > 1)
		{
			stack_free(stack);
			quit("Duplication detected\n");
		}
		temp = temp->next;
	}
	return ;
}

static int	error_notnumber(char *str)
{
	int	num;

	if (!str)
		return (-1);
	if (ft_strlen(str) > 10)
		return (-1);
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
	int		idx;
	int		jdx;
	char	**list;

	idx = 1;
	while (av[idx])
	{
		list = ft_split(av[idx], ' ');
		if (!list)
			quit("Allocation failed\n");
		jdx = 0;
		while (list[jdx])
		{
			if (error_notnumber(list[jdx]) == -1)
			{
				ft_double_free(list);
				quit("non numbers detected\n");
			}
			jdx++;
		}
		ft_double_free(list);
		idx++;
	}
}

