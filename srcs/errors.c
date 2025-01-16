#include "../includes/push_swap.h"

static void	quit(void)
{
	printf("Error\n");
	exit(0);
}

static void	error_duplicate(char **av, char *arg, int position)
{
	int	idx;
	if (!av || !arg)
		return ;

	idx = 1;
	while (av[idx])
	{
		if (ft_strcmp(av[idx], arg) == 0 && idx != position)
			quit();
		idx++;
	}
}

static void	error_notnumber(char *str)
{
	int	num;

	if (!str)
		return ;
	if (ft_strlen(str) > 10)
		quit();
	num = ft_atoi(str);
	if (num == 0)
	{
		if (ft_strcmp(str,"0") && ft_strcmp(str,"-0") && ft_strcmp(str,"-0"))
			quit();
	}
	if (num == -1 && ft_strcmp(str, "-1"))
		quit();
}

void	error_check(char **av)
{
	int	idx;

	idx = 1;
	while (av[idx])
	{
		error_duplicate(av, av[idx], idx);
		error_notnumber(av[idx]);
		idx++;
	}
}

