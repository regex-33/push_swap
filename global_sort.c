/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:43 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/21 19:29:45 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_elem(stack, len)]
		|| elem < stack[find_min_elem(stack, len)])
		place = find_min_elem(stack, len);
	else
	{
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) || (i
						+ 1 == len && elem < stack[0])))
			{
				return (find_a_rot_type(len, i + 1, rot_type));
			}
			i++;
		}
	}
	return (find_a_rot_type(len, place, rot_type));
}

static void	insert_back_in_a(t_stack *stack)
{
	int		num_of_rots;
	char	*rot_type;

	num_of_rots = 0;
	rot_type = ft_calloc(3, sizeof(char));
	while (stack->b_size)
	{
		num_of_rots = find_place_in_a(stack->stack_a, stack->a_size,
				stack->stack_b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (!ft_strcmp(rot_type, "ra"))
				apply_ra(stack, 0);
			else
				apply_rra(stack, 0);
			num_of_rots--;
		}
		apply_pa(stack, 0);
	}
	place_smallest_first_a(stack);
	free(rot_type);
}

static void	insert_leftover_to_b(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack->a_size > 2)
	{
		idx = find_min_elem(stack->stack_a, stack->a_size);
		if (idx == 0)
			apply_pb(stack, 0);
		else if (idx <= stack->a_size / 2)
			apply_ra(stack, 0);
		else if (idx > stack->a_size / 2)
			apply_rra(stack, 0);
	}
}

static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (!ft_strcmp(best_move->a_rot_type, "ra"))
			apply_ra(stack, 0);
		else
			apply_rra(stack, 0);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (!ft_strcmp(best_move->b_rot_type, "rb"))
			apply_rb(stack, 0);
		else
			apply_rrb(stack, 0);
		best_move->b_moves--;
	}
}

void	global_sort(t_stack *stack)
{
	t_moves	*best_move;
	int		optimizer;

	optimizer = 2;
	if (stack->a_size > 200)
		optimizer = 50;
	while (stack->b_size != 2)
		apply_pb(stack, 0);
	while (stack->a_size > optimizer)
	{
		best_move = best_way_from_a_to_b(stack);
		while (best_move->common_moves)
		{
			if (!ft_strcmp(best_move->common_rot, "rr"))
				apply_rr(stack);
			else
				apply_rrr(stack);
			best_move->common_moves--;
		}
		process_moves(best_move, stack);
		apply_pb(stack, 0);
		free_moves(best_move);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
}
