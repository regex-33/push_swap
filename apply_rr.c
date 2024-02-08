/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:08 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:29:09 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ra(t_stack *stack, int i)
{
	int	tmp;

	if (stack->a_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_a[0];
	while (i < stack->a_size)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	if (stack->print_instr)
		ft_printf("ra\n");
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

void	apply_rb(t_stack *stack, int i)
{
	int	tmp;

	if (stack->b_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_b[0];
	while (i < stack->b_size)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	if (stack->print_instr)
		ft_printf("rb\n");
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

void	apply_rr(t_stack *stack)
{
	int	tmp_instr;
	int	tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->print_stack = 0;
	apply_ra(stack, 0);
	apply_rb(stack, 0);
	stack->print_instr = tmp_instr;
	stack->print_stack = tmp_stack;
	if (stack->print_instr)
		ft_printf("rr\n");
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
