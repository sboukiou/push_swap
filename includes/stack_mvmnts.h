/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mvmnts.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:17:51 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:18:06 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MVMNTS_H
# define STACK_MVMNTS_H

# include "./common.h"

void	find_and_push(t_stack *stack_a, t_stack *stack_b, int value);
void	sab(t_stack	*stack, char *str);
void	rab(t_stack	*stack, char *str);
void	rrab(t_stack	*stack, char *str);
void	pab(t_stack *a, t_stack *b, char *str);
#endif
