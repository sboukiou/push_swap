#ifndef TYPES_H
# define TYPES_H

typedef struct	s_node
{
	int		value;
	s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node	*bottom;
} t_stack;

#endif
