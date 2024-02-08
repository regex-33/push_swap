/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:28:50 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:28:52 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sa(t_stack *stack)
{
	int	tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if (stack->print_instr)
		ft_printf("sa\n");
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

void	apply_sb(t_stack *stack)
{
	int	tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	if (stack->print_instr)
		ft_printf("sb\n");
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

void	apply_ss(t_stack *stack)
{
	int	tmp_instr;
	int	tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->print_stack = 0;
	apply_sa(stack);
	apply_sb(stack);
	stack->print_instr = tmp_instr;
	stack->print_stack = tmp_stack;
	if (stack->print_instr)
		ft_printf("ss\n");
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

void	apply_pa(t_stack *stack, int i)
{
	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i-- > 0)
		stack->stack_a[i + 1] = stack->stack_a[i];
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i++ <= stack->b_size)
		stack->stack_b[i - 1] = stack->stack_b[i];
	stack->a_size++;
	stack->b_size--;
	if (stack->print_instr)
		ft_printf("pa\n");
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

void	apply_pb(t_stack *stack, int i)
{
	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i-- > 0)
		stack->stack_b[i + 1] = stack->stack_b[i];
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i++ <= stack->a_size - 1)
		stack->stack_a[i - 1] = stack->stack_a[i];
	stack->b_size++;
	stack->a_size--;
	if (stack->print_instr)
		ft_printf("pb\n");
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
