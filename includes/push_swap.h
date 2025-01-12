/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:08:28 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/09 02:10:42 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Main header file*/
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/*#include "../libft/libft.h"*/
#include "./common.h"


/*Stack dsa functions*/
t_node	*stack_create_node(int value, t_node *prev);
t_stack	*stack_push_back(t_stack *stack, t_node *node);
t_stack	*stack_push_front(t_stack *stack, t_node *node);
void	stack_free(t_stack *stack_data);
void	stack_print(t_stack *stack_data);
t_stack	*stack_last(t_stack *stack_data);
void	sort_stack(t_stack *stack_data);
void	stack_swap(t_node *node_a, t_node *node_b);
t_stack	*stack_duplicate(t_stack *stack);

/*Stack movements*/
void	rab(t_stack *stack);
void	sab(t_stack *stack);
void	rrab(t_stack *stack);
void	pab(t_stack *a, t_stack *b);
/*prototypes for src*/
t_stack	*tokenize_input(char **input);
#endif
