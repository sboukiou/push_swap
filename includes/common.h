/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:13:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/30 11:16:05 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

/*Include external functions*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*Structures*/
struct	s_stack_node
{
	int					value;
	struct s_stack_node	*next;

};
typedef struct s_stack_node	t_node;

struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
};
typedef struct s_stack		t_stack;

#endif
