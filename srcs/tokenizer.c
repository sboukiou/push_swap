#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_perror(void)
{
	write(STDIN_FILENO, "Error\n", 6);
	exit(0);
}

int	isvalid_number(char *string)
{
	long	number;

	if (!string)
		return (0);
	number = ft_atoi(string);
	if (number == 0 && (ft_strncmp(string, "0", 1)))
		return (0);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

size_t	count_elements(char **input)
{
	int	count;
	int	idx;
	int	jdx;
	char	**list;

	idx = 1;
	jdx = 0;
	count = 0;
	if (!input)
		return (-1);
	while (input[idx])
	{
		list = ft_split(input[idx], ' ');
		if (!list)
			return (-1);
		jdx = 0;
		while (list[jdx])
		{
			if (!isvalid_number(list[jdx]))
			{
				ft_double_free(list);
				ft_perror();
			}
			count++;
			jdx++;
		}
		ft_double_free(list);
		idx++;
	}
	return (count);
}

int	*split_input(char **av, int ac)
{
	int	*stack_a;
	int	idx;
	int	jdx;
	char	**list;

	(void)ac;
	if (!av)
		return (NULL);
	idx = 1;
	int	count = count_elements(av);
	stack_a = (int *)malloc(sizeof(int) * (count + 1));
	if (!stack_a)
		ft_perror();
	count = 0;
	while (av[idx])
	{
		list = ft_split(av[idx], ' ');
		if (!list)
			ft_perror();
		jdx = 0;
		while (list[jdx])
		{
			stack_a[count] = ft_atoi(list[jdx]);
			count++;
			jdx++;
		}
		ft_double_free(list);
		idx++;
	}
	return (stack_a);
}

/*void	parse_input(t_metadata *metadata, int ac, char **av)*/
/*{*/
/*	int	idx;*/
/*	int	*stack_a;*/
/**/
/*	split_input(av, ac);*/
/*	stack_a = (int *)malloc(sizeof(int) * ac + 1);*/
/*	if (!stack_a)*/
/*		return ;*/
/*	idx = 0;*/
/*	while (av[idx])*/
/*	{*/
/**/
/*		idx++;*/
/*	}*/
/*}*/
