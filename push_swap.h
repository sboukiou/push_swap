/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:25:43 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/02 11:27:07 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*Includes for std functions*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*Other utils headers*/
# include "./libft/libft.h"

/*Types definitions*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void	stack_print(t_stack *stack);

/*list tools prototypes | All defined at --> ./llist_tools.c */
t_node	*new_node(int value);
t_stack	*stack_new(t_node *top, t_node *bottom);
void	stack_push_back(t_stack *stack, t_node *node);
void	stack_push_front(t_stack *stack, t_node *node);
int		stack_size(t_stack *stack);
void	stack_free(t_stack *stack);
int		stack_issorted(t_stack *stack);
void	stack_remove(t_stack *stack, t_node *node);
int		stack_index_of(t_stack *stack, int value);
void	stack_swap(t_node *node_a, t_node *node_b);
void	stack_sort(t_stack *stack);
t_stack	*stack_duplicate(t_stack *stack);

/* Stack Actions */
void	pab(t_stack *stack_a, t_stack *stack_b, char *str);
void	sab(t_stack *stack, char *str);
void	rab(t_stack *stack, char *str);
void	rrab(t_stack *stack, char *str);
void	find_and_push_a(t_stack *stack_a, t_stack *stack_b, int value);
void	find_and_push_b(t_stack *stack_a, t_stack *stack_b, int value);

/*Parser function | defined at --> ./parser.c */
t_stack	*parser(char **av);
void	sort_size_four_five(t_stack *stack_a, t_stack *stack_b);
void	sort_size_three(t_stack *stack_a);
void	sorter(t_stack *stack_a, t_stack *stack_b);

/*Array ref utils*/
int		includes(int *ref, int value, int range);
int		*create_ref_array(t_stack *stack);
void	array_sort(int *arr, int size);
void	expand_range(int *start, int *end, int size);

#endif
