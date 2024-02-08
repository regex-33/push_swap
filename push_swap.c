/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:30:03 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/25 20:21:26 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*concatenate_arguments(char **argv)
{
	char	*temp;
	char	*new_temp;
	int		i;

	i = 0;
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
	while (temp[i])
		if (ft_isalpha(temp[i++]))
			return (0);
	return (temp);
}

static int	process_and_validate_input(char **argv, t_stack *stack)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	if (count == 0)
	{
		ft_putstr_fd("Error", 2);
		free_split(argv);
		free_stack(stack);
		return (0);
	}
	if (!init_stack_struct(stack, count))
	{
		free_split(argv);
		free_stack(stack);
		return (0);
	}
	stack = parse_args(count, argv, stack);
	sort(stack);
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
		free(stack);
		free(temp);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	argv = ft_split(temp, ' ');
	free(temp);
	if (!process_and_validate_input(argv, stack))
		exit(1);
	return (0);
}
