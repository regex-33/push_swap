/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:15 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:29:17 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra(t_stack *stack, int i)
{
	int	tmp;

	if (stack->a_size == 0)
		return ;
	i = stack->a_size - 1;
	tmp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (stack->print_instr)
		ft_printf("rra\n");
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}

void	apply_rrb(t_stack *stack, int i)
{
	int	tmp;

	if (stack->b_size == 0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (stack->print_instr)
		ft_printf("rrb\n");
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}

void	apply_rrr(t_stack *stack)
{
	int	tmp_instr;
	int	tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->print_stack = 0;
	apply_rra(stack, 0);
	apply_rrb(stack, 0);
	stack->print_instr = tmp_instr;
	stack->print_stack = tmp_stack;
	if (stack->print_instr)
		ft_printf("rrr\n");
	if (stack->print_stack)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->b_size)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->stack_b, stack->b_size);
		}
	}
	stack->total_instr++;
}
