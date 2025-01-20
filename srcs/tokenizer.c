#include "../includes/push_swap.h"
#include "../includes/common.h"
#include "../includes/libft.h"

int	is_zero(char *str)
{
	int	zero;
	int	zerop;
	int	zeron;
	if (ft_strlen(str) > 2)
		return (0);
	zero = ft_strncmp("0", str, 1);
	zerop = ft_strncmp("+0", str, 2);
	zeron = ft_strncmp("-0", str, 2);
	if (zero && zerop && zeron)
		return (0);
	return (1);
}



static void	extract_list(char **list, t_stack *stack)
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
		stack_push_back(stack, temp);
		idx++;
	}
}

t_stack	*tokenize_input(char **input)
{
	t_stack	*stack;
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
