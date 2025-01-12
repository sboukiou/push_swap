#include "../includes/push_swap.h"
#include "../includes/common.h"
#include "../includes/libft.h"

static void	extract_list(char **list, t_stack *stack)
{
	int		idx;
	int		data;
	t_node	*temp;

	idx = 0;
	while (list[idx])
	{
		data = atoi(list[idx]);
		temp = stack_create_node(data, stack->bottom);
		if (!temp)
			return ;
		stack_push_back(stack, temp);
		idx++;
	}
}

t_stack	*tokenize_input(char **input)
{
	t_stack	*stack;
	t_node			*temp;
	int				i;
	 char			**list;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	while (input[i])
	{
		list = ft_split(input[i], ' ');
		if (!list)
			return (NULL);
		extract_list(list, stack);
		ft_double_free(list);
		i++;
	}
	return (stack);
}
