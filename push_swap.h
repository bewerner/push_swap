/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:23:07 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:51:27 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_push_swap
{
	int		initial_size;
	int		size_a;
	int		size_b;
	int		*a;
	int		*b;
	int		*cost;
	int		*pin;
	int		first_pin_i;
	int		last_pin_i;
	int		initial_pin_nbr;
	int		pin_count;
	int		pin_i;
	int		swap_i;
	int		prev_pin_i;
	int		next_pin_i;
	int		print_stacks;
	int		instruction_count;
	int		chunk_size;
	int		min_b;
	int		max_b;
	int		min_b_i;
	int		max_b_i;
	int		min_a;
	int		max_a;
	int		min_a_i;
	int		max_a_i;
	int		swap_cost;
	int		print_instructions;
	int		best_run;
	int		best_swap_cost;
	int		group_count;
	int		group_size;
	int		argc;
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
