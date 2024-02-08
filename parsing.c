/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:52 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/25 19:35:05 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_args(char **argv, char *arg, int start)
{
	int	i;

	i = 0;
	while (*arg && arg[i + 1] != '\0')
	{
		if ((arg[i] == '-' || arg[i] == '+') && !ft_isdigit(arg[i + 1]))
			return (0);
		else if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (0);
		else if (ft_isdigit(arg[i]) && (arg[i + 1] == '-' || arg[i + 1] == '+'))
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (argv[start] && argv && arg)
	{
		if (!ft_strcmp(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

int	init_stack_struct(t_stack *stack, int argc)
{
	stack->stack_a = (int *)ft_calloc(argc, sizeof(int));
	if (!stack->stack_a)
		return (free(stack), 0);
	stack->stack_b = (int *)ft_calloc(argc, sizeof(int));
	if (!stack->stack_b)
		return (free(stack->stack_a), free(stack), 0);
	stack->a_size = argc;
	stack->b_size = 0;
	stack->total_instr = 0;
	stack->print_instr = 1;
	return (1);
}

int	parse_options(int *argc, char ***argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->total = 0;
	stack->color = 0;
	stack->print_stack = 0;
	while (i < *argc && *((*argv)[i]) == '-')
	{
		if (!ft_strcmp((*argv)[i], "-v"))
			stack->print_stack = 1;
		else if (!ft_strcmp((*argv)[i], "-t"))
			stack->total = 1;
		else if (!ft_strcmp((*argv)[i], "-c"))
			stack->color = 1;
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("usage: ./push_swap [-v -c -t] [numbers...]\n", 2);
			exit(1);
		}
		i++;
	}
	*argc -= i;
	*argv += i;
	return (i);
}

t_stack	*parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->stack_a[i] = ft_atoi(argv[i]);
		else
		{
			free_stack(stack);
			free_split(argv);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
