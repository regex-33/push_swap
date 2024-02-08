/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:24 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:29:25 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *stack)
{
	if (stack->print_stack)
	{
		if (stack->color)
			ft_putstr(MAG);
		ft_printf("Sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
	}
	if (stack->total)
	{
		if (stack->color)
			ft_putstr(BLUE);
		ft_printf("Total %d operations\n", stack->total_instr);
		if (stack->color)
			ft_putstr(NC);
	}
}

static void	sort_3(t_stack *stack)
{
	int	max_idx;

	if (stack->a_size == 1)
		return ;
	if (stack->a_size == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
		return ;
	}
	else if (stack->a_size == 3)
	{
		max_idx = find_max_elem(stack->stack_a, stack->a_size);
		if (max_idx == 0)
			apply_ra(stack, 0);
		if (max_idx == 1)
			apply_rra(stack, 0);
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
	}
}

void	sort(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->a_size) && stack->b_size == 0)
		return ;
	if (stack->print_stack)
	{
		if (stack->color)
			ft_putstr(MAG);
		ft_printf("Pre-sorted array: ");
		ft_print_int_array(stack->stack_a, stack->a_size);
		if (stack->color)
			ft_putstr(CYAN);
	}
	if (stack->a_size <= 3)
		return (sort_3(stack));
	else
		global_sort(stack);
	if (stack->print_stack && stack->total)
		ft_printer(stack);
}
