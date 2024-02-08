/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:08:01 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/24 17:08:02 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleanup(t_stack *stack, char **argv)
{
	ft_putstr_fd("Error", 2);
	free_split(argv);
	free_stack(stack);
	exit(1);
}

void	free_split(char **str)
{
	while (*str)
		free(*str++);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
}
