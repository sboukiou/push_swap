#include "../includes/push_swap.h"

static void	quit(void)
{
	printf("Error\n");
	exit(0);
}

static int not_only_zeros(char *string)
{
	int idx;

	idx = 0;
	while (string[idx])
	{
		if (string[idx] != '0')
			return (1);
		idx++;
	}
	return (0);
}

static int	not_numerical(char *string)
{
	if (ft_strlen(string) > 10 && not_only_zeros(string))
		return (1);
	if (ft_atoi(string) == 0)
	{
		if (ft_strlen(string) > 2)
			return (1);
		if (ft_strcmp(string, "0") && ft_strcmp(string, "-0") && ft_strcmp(string, "-0"))
			return (1);
	}
	if (ft_atoi(string) == -1 && ft_strcmp(string, "-1"))
		return (1);
	return (0);
}

/*static int	deja_vue(char **args, char *string)*/
/*{*/
/*	int		idx;*/
/*}*/

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

