#include "../includes/push_swap.h"

static void	quit(void)
{
	printf("Error\n");
	exit(0);
}

static int	not_numerical(char *string)
{
	if (ft_strlen(string) > 10)
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

static int	deja_vue(char **args, char *string)
{
	int		idx;
	int		count;

	if (!args || !string)
		return (1);
	idx = 0;
	count = 0;
	while (args[idx])
	{
		if (ft_strcmp(args[idx], string) == 0)
			count++;
		idx++;
	}
	if (count > 1)
		return (1);
	return (0);
}

static char	**join_args(char **av)
{
	int	idx;
	char	*buffer;
	char	**args;
	char	*temp;

	idx = 1;
	buffer = ft_strjoin("", " ");
	while (av[idx])
	{
		temp = buffer;
		buffer = ft_strjoin(buffer, av[idx]);
		free(temp);
		temp = buffer;
		buffer = ft_strjoin(buffer, " ");
		free(temp);
		if (!buffer)
			quit();
		idx++;
	}
	args = ft_split(buffer, ' ');
	free(buffer);
	return (args);
}

void	error_check(char **av)
{
	char	**args;
	int	idx;

	args = join_args(av);
	if (!args)
		quit();
	idx = 1;
	while (args[idx])
	{
		if (deja_vue(args, args[idx]) || not_numerical(args[idx]))
		{
			ft_double_free(args);
			quit();
		}
		idx++;
	}
	ft_double_free(args);
}

