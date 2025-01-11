#include "../includes/push_swap.h"
#include "../includes/common.h"
#include "../includes/libft.h"

static void	extract_list(char **list, t_node **stack)
{
	int		idx;
	int		data;
	t_node	*temp;

	idx = 0;
	while (list[idx])
	{
		data = atoi(list[idx]);
		temp = stack_create_node(data);
		if (!temp)
			return ;
		stack_push(stack, temp);
		idx++;
	}
}

t_node	*tokenize_input(char **input)
{
	t_node	*stack;
	t_node	*temp;
	int		idx;
	int		i;
	int		data;
	 char	**list;

	i = 1;
	stack = NULL;

	while (input[i])
	{
		list = ft_split(input[i], ' ');
		if (!list)
			return (NULL);
		extract_list(list, &stack);
		ft_double_free(list);
		i++;
	}
	return (stack);
}
