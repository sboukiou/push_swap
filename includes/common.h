#ifndef COMMON_H
# define COMMON_H

/*Include external functions*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


/*Structures*/
struct	stack_node
{
	int					value;
	struct	stack_node	*next;

};
typedef struct stack_node t_node;

struct	stack
{
	t_node	*top;
	t_node	*bottom;
};
typedef struct stack t_stack;

#endif
