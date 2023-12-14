/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:23:07 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/12 02:20:21 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_push_swap
{
	int		initial_size;
	int		size_a;
	int		size_b;
	int		*a;
	int		*b;
	int		*cost;
	int		instruction_count;
	int		min_a;
	int		max_a;
	int		min_a_i;
	int		max_a_i;
	int		group_count;
	int		group_size;
	int		argc;
	int		print_instructions;
}			t_push_swap;

void	map_to_sorted_index(int j, int i, t_push_swap *s);
void	init_stacks(t_push_swap *s, char **argv);
void	push_swap(t_push_swap *s, char **argv);
void	whitespace_to_space(char *str);
int		is_unique(int n, int i, t_push_swap *s);
int		is_in_range(char *nbstr, char *min, char *max);
int		is_numeric(char *str);
void	validate(char *str, char **argv, int i, t_push_swap *s);
void	set_min_max_a(t_push_swap *s);
int		a_is_sorted(t_push_swap *s);
void	sort_three(t_push_swap *s);
int		rotate_to_top_cost(int i_a, int i_b, t_push_swap *s);
void	set_cost(t_push_swap *s);
void	rotate_a_b(int a, int b, t_push_swap *s);
void	rotate_to_top(int i_a, int i_b, t_push_swap *s);
int		get_group(int n, t_push_swap *s);
int		group_size(int group, t_push_swap *s);
int		first_of(int group, t_push_swap *s);
void	set_group_count(t_push_swap *s);
void	presort(t_push_swap *s);
int		biggest_group_in_b(t_push_swap *s);
int		get_i_of_cheapest(t_push_swap *s);
int		get_i_of_target(int i_b, t_push_swap *s);
void	final_sort(t_push_swap *s);
void	free_argv(char **argv, t_push_swap *s);
void	free_stacks(t_push_swap *s);
void	put_error(char *error_message, char **argv, t_push_swap *s);
void	operate(char *instruction, t_push_swap *s);
void	op_shift_down(char *instruction, t_push_swap *s);
void	op_shift_up(char *instruction, t_push_swap *s);
void	op_push_b(t_push_swap *s);
void	op_push_a(t_push_swap *s);
void	op_swap(char *instruction, t_push_swap *s);

#endif
