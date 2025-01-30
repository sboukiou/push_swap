/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:16:53 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:17:17 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "./common.h"

/*Stack dsa functions*/
t_node	*stack_create_node(int value);
void	stack_push_back(t_stack *stack, t_node *node);
void	stack_push_front(t_stack *stack, t_node *node);
void	stack_free(t_stack *stack_data);
void	stack_print(t_stack *stack_data);
t_stack	*stack_last(t_stack *stack_data);
void	stack_sort(t_stack *stack_data);
void	stack_swap(t_node *node_a, t_node *node_b);
t_stack	*stack_duplicate(t_stack *stack);
void	stack_remove(t_stack *stack, t_node *node);
int		stack_index_of(t_stack *stack, int value);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
t_node	*stack_find_prev(t_stack *stack, int value);
t_node	*stack_smallest(t_stack *stack);
#endif
