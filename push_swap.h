#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*Includes for std functions*/
# include <unistd.h>
# include <stdlib.h>

/*Other utils headers*/
#include "./libft/libft.h"

/*Types definitions*/
typedef struct	s_node
{
	int				value;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node	*bottom;
} t_stack;


/*list tools prototypes | All defined at --> ./llist_tools.c */
t_node	*new_node(int value);
t_stack	*stack_new(t_node *top, t_node *bottom);
void	stack_push_back(t_stack *stack, t_node *node);
void	stack_push_front(t_stack *stack, t_node *node);
int	stack_size(t_stack *stack);
void	stack_free(t_stack *stack);


/*Parser function | defined at --> ./parser.c */
t_stack	*parser(char **av);

#endif
