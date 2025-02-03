/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:56:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:35 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/*Includes for std functions*/
# include <unistd.h>
# include <stdlib.h>

/*Other utils headers*/
# include "./libft/libft.h"
# include "push_swap.h"

int		move_isvalide(char *move);
void	quit(t_stack *stack_a, t_stack *stack_b);
void	apply_move(t_stack *stack_a, t_stack *stack_b, char *move);
#endif
