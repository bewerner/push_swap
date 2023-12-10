/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:32:19 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:41:20 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_group_in_b(t_push_swap *s)
{
	int	i;
	int	group;

	i = 1;
	group = 1;
	while (i <= s->size_b)
	{
		if (get_group(s->b[i], s) > group)
			group = get_group(s->b[i], s);
		i++;
	}
	return (group);
}

int	get_i_of_cheapest(t_push_swap *s)
{
	int	group;
	int	cheapest;
	int	cheapest_i;
	int	i;

	if (!s->size_b)
		return (0);
	group = biggest_group_in_b(s);
	i = 1;
	while (get_group(s->b[i], s) != group)
		i++;
	cheapest = s->b[i];
	cheapest_i = i;
	while (i <= s->size_b)
	{
		if (s->cost[i] < cheapest && get_group(s->b[i], s) == group)
		{
			cheapest = s->cost[i];
			cheapest_i = i;
		}
		i++;
	}
	return (cheapest_i);
}

int	get_i_of_target(int i_b, t_push_swap *s)
{
	int	i;
	int	target_i;

	set_min_max_a(s);
	if (s->b[i_b] < s->min_a || s->b[i_b] > s->max_a)
		return (s->min_a_i);
	i = 1;
	target_i = s->max_a_i;
	while (i <= s->size_a)
	{
		if (s->b[i_b] < s->a[i])
			if (s->a[i] < s->a[target_i])
				target_i = i;
		i++;
	}
	return (target_i);
}

void	final_sort(t_push_swap *s)
{
	int	i_cheapest;
	int	i_target;

	while (s->size_b)
	{
		set_cost(s);
		i_cheapest = get_i_of_cheapest(s);
		i_target = get_i_of_target(i_cheapest, s);
		rotate_to_top(i_target, i_cheapest, s);
		operate("pa", s);
	}
	set_min_max_a(s);
	rotate_to_top(s->min_a_i, 1, s);
}
