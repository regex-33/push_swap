/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:37 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/25 19:17:44 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_instruction(t_stack *stack, char *instr)
{
	if (!ft_strcmp(instr, "sa\n"))
		apply_sa(stack);
	else if (!ft_strcmp(instr, "sb\n"))
		apply_sb(stack);
	else if (!ft_strcmp(instr, "ss\n"))
		apply_ss(stack);
	else if (!ft_strcmp(instr, "pa\n"))
		apply_pa(stack, 0);
	else if (!ft_strcmp(instr, "pb\n"))
		apply_pb(stack, 0);
	else if (!ft_strcmp(instr, "ra\n"))
		apply_ra(stack, 0);
	else if (!ft_strcmp(instr, "rb\n"))
		apply_rb(stack, 0);
	else if (!ft_strcmp(instr, "rr\n"))
		apply_rr(stack);
	else if (!ft_strcmp(instr, "rra\n"))
		apply_rra(stack, 0);
	else if (!ft_strcmp(instr, "rrb\n"))
		apply_rrb(stack, 0);
	else if (!ft_strcmp(instr, "rrr\n"))
		apply_rrr(stack);
	else
		return (-1);
	return (0);
}

static void	do_instruction(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		if (get_instruction(stack, line) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

static char	*concatenate_arguments(char **argv)
{
	char	*temp;
	char	*new_temp;

	temp = NULL;
	while (*argv)
	{
		new_temp = ft_strjoin(temp, *argv++);
		if (new_temp)
		{
			free(temp);
			temp = ft_strjoin(new_temp, " ");
			free(new_temp);
		}
		else
		{
			free(temp);
			return (NULL);
		}
	}
	return (temp);
}

static int	process_and_validate_input(char **argv, t_stack *stack)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	if (count == 0)
		ft_cleanup(stack, argv);
	if (!init_stack_struct(stack, count))
		ft_cleanup(stack, argv);
	stack = parse_args(count, argv, stack);
	stack->print_instr = 0;
	if (!(is_sorted(stack->stack_a, stack->a_size)))
		do_instruction(stack);
	if (is_sorted(stack->stack_a, stack->a_size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack);
	free_split(argv);
	free(argv);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	*temp;

	temp = NULL;
	if (argc-- == 1)
		exit(0);
	else
		argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	parse_options(&argc, &argv, stack);
	temp = concatenate_arguments(argv);
	if (!temp)
	{
		free_split(argv);
		free_stack(stack);
		return (0);
	}
	argv = ft_split(temp, ' ');
	free(temp);
	if (!process_and_validate_input(argv, stack))
		exit(1);
	return (0);
}
