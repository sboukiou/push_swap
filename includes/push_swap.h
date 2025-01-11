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

/*Include external functions*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/*#include "../libft/libft.h"*/

/*Structures*/
struct	stack_node
{
	int					value;
	struct	stack_node	*next;

};
typedef struct stack_node t_node;

/*Stack dsa functions*/
t_node	*stack_create_node(int value);
t_node	*stack_push(t_node **head, t_node	*node);
void	stack_free(t_node **head);
void	stack_print(t_node *head);

/*prototypes for src*/
t_node	*tokenize_input(char **input);
#endif
