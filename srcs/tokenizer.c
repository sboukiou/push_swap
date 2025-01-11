#include "../includes/push_swap.h"
#include <stdio.h>

void	free_str_array(char **list)
{
	int	idx;

	idx = 0;
	while (list[idx])
	{
		free(list[idx]);
		list[idx] = NULL;
		idx++;
	}
	free(list);
	list = NULL;
}


t_node	*tokenize_input(char **input)
{
	t_node	*numbers;
	t_node	*temp;
	int		idx;
	int		data;
	 char	**list;

	idx = 1;
	numbers = NULL;
	while (input[idx])
	{
		/*list = ft_split(input[idx], ' ');*/
		/*if (!list)*/
		/*	return (NULL);*/
		data = atoi(input[idx]);
		temp = stack_create_node(data);
		if (!temp)
			return (NULL);
		stack_push(&numbers, temp);
		idx++;
	}
	return (numbers);
}
