/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:56:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/02/03 09:59:50 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/*Includes for std functions*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*Other utils headers*/
# include "./libft/libft.h"
typedef struct s_action {
	char			*name;
	struct s_action	*next;
}	t_action;

#endif
