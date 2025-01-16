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
#include "./tokenizer.h"
#include "./metadata.h"
#include "./libft.h"


/*Stack dsa functions*/
int	*stack_duplicate(int *stack, size_t size);
void	stack_print(int *stack, size_t size);

/*Stack movements*/
void	sab(int	*stack, size_t size);
/*prototypes for src*/
#endif
