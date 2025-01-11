#ifndef COMMON_H
# define COMMON_H

/*Include external functions*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*Structures*/
struct	stack_node
{
	int					value;
	struct	stack_node	*next;

};
typedef struct stack_node t_node;

#endif
