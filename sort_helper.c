/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:30:24 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:30:25 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *stack, int len)
{
	int	i;
	int	tmp;
	int	index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max_index(int *stack, int len)
{
	int	i;
	int	tmp;
	int	index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_min_elem(int *stack, int stack_len)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max_elem(int *stack, int stack_len)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_a(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack->stack_a, stack->a_size);
	if (min_index <= stack->a_size / 2)
		while (min_index--)
			apply_ra(stack, 0);
	else
	{
		while ((stack->a_size - min_index) > 0)
		{
			apply_rra(stack, 0);
			min_index++;
		}
	}
}
