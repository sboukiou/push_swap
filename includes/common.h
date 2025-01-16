#ifndef COMMON_H
# define COMMON_H

/*Include external functions*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <limits.h>

/*First argument ---> Top of the stack*/
/*Moves --> | sa sb ss ra ra rr rra rra rrr*/
			/*sa : Swap top 2 elements of stack a*/
			/*sb : Swap top 2 elements of stack a*/

/*Structures*/
struct	stack_node
{
	int					value;
	struct	stack_node	*next;
	struct	stack_node	*prev;

};
typedef struct stack_node t_node;

struct	stack
{
	t_node	*top;
	t_node	*bottom;
};
typedef struct stack t_stack;

#endif
