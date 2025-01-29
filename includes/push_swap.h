/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:08:28 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:29 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Main header file*/
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/*#include "../libft/libft.h"*/
#include "./common.h"
#include "./error.h"
#include "./lists.h"
#include "./stack_mvmnts.h"



/*prototypes for src*/
t_stack	*tokenize_input(char **input);
void	sorter(t_stack *stack_a, t_stack *stack_b);
#endif
