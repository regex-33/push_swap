/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:33:38 by yachtata          #+#    #+#             */
/*   Updated: 2023/12/25 19:41:14 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>

# define MAG "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define NC "\033[0m"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		a_size;
	int		b_size;
	int		color;
	int		total;
	int		print_stack;
	int		total_instr;
	int		print_instr;
}			t_stack;

typedef struct s_moves
{
	int		elem;
	int		a_moves;
	char	*a_rot_type;
	char	*b_rot_type;
	char	*common_rot;
	int		b_moves;
	int		common_moves;
	int		total;
}			t_moves;

void		free_split(char **str);
void		apply_sa(t_stack *stack);
void		apply_sb(t_stack *stack);
void		apply_ss(t_stack *stack);
void		apply_pa(t_stack *stack, int i);
void		apply_pb(t_stack *stack, int i);
void		apply_ra(t_stack *stack, int i);
void		apply_rb(t_stack *stack, int i);
void		apply_rr(t_stack *stack);
void		apply_rra(t_stack *stack, int i);
void		apply_rrb(t_stack *stack, int i);
void		apply_rrr(t_stack *stack);
void		sort(t_stack *stack);
void		global_sort(t_stack *stack);
t_moves		*best_way_from_a_to_b(t_stack *stack);
void		ft_cleanup(t_stack *stack, char **argv);

int			find_a_rot_type(int len, int pos, char **a_rot_type);
int			find_b_rot_type(int len, int pos, char **b_rot_type);

int			find_min_elem(int *stack, int stack_len);
int			find_max_elem(int *stack, int stack_len);
int			find_min_index(int *stack, int len);
int			find_max_index(int *stack, int len);
void		place_smallest_first_a(t_stack *stack);

int			is_sorted(int *stack, int len);
int			is_reverse_sorted(int *stack, int len);
void		free_stack(t_stack *stack);
void		free_moves(t_moves *moves);

int			init_stack_struct(t_stack *stack, int argc);
int			parse_options(int *argc, char ***argv, t_stack *stack);
t_stack		*parse_args(int argc, char **argv, t_stack *stack);

#endif
