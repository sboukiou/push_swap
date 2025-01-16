#ifndef METADATA_H
#define METADATA_H
#include <stddef.h>
typedef struct metadata
{
	int	*stack_a;
	int	*stack_b;
	int	size;
	int	top;
	int	bottom;
} t_metadata;

size_t	count_elements(char **input);
int	*split_input(char **av, int ac);
#endif
