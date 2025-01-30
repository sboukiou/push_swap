/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:08:28 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:17:38 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Main header file*/
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*#include "../libft/libft.h"*/
# include "./common.h"
# include "./error.h"
# include "./lists.h"
# include "../libft/libft.h"
# include "./stack_mvmnts.h"

/*prototypes for src*/
t_stack	*stack_init(char **args);
void	sorter(t_stack *stack_a, t_stack *stack_b);
#endif
