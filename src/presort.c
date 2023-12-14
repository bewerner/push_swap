/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:30:24 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:31:46 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_group(int n, t_push_swap *s)
{
	int	group;

	group = 1;
	while (group < s->group_count)
	{
		if (n <= s->group_size * group)
			return (group);
		group++;
	}
	return (group);
}

int	group_size(int group, t_push_swap *s)
{
	int	i;
	int	members;

	i = 1;
	members = 0;
	while (i <= s->size_b)
	{
		if (get_group(s->b[i], s) == group)
			members++;
		i++;
	}
	return (members);
}

int	first_of(int group, t_push_swap *s)
{
	int	i;

	i = 1;
	while (!group_size(group, s) && s->size_b)
		group--;
	while (get_group(s->b[i], s) != group && s->size_b)
		i++;
	return (i);
}

void	set_group_count(t_push_swap *s)
{
	s->group_count = 2;
	if (s->initial_size > 70)
		s->group_count = 4;
	if (s->initial_size > 200)
		s->group_count = 6;
	if (s->initial_size > 700)
		s->group_count = 8;
	if (s->initial_size > 1100)
		s->group_count = 10;
	if (s->initial_size > 2600)
		s->group_count = 12;
	if (s->initial_size > 3800)
		s->group_count = 14;
	if (s->initial_size > 5000)
		s->group_count = 16;
	if (s->initial_size > 6000)
		s->group_count = 18;
	if (s->initial_size > 12000)
		s->group_count = 20;
	s->group_size = s->initial_size / s->group_count;
}

void	presort(t_push_swap *s)
{
	int	top;
	int	bottom;

	set_group_count(s);
	bottom = s->group_count / 2;
	top = bottom + 1;
	while (s->size_a > 3 && !a_is_sorted(s))
	{
		if (get_group(s->a[1], s) == top && get_group(s->b[1], s) != top)
			rotate_to_top(1, first_of(top, s), s);
		if (get_group(s->a[1], s) == top || get_group(s->a[1], s) == bottom)
			operate("pb", s);
		else if (get_group(s->b[1], s) == bottom)
			operate("rr", s);
		else
			operate("ra", s);
		if (group_size(top, s) == s->group_size && top != s->group_count)
			top++;
		if (group_size(bottom, s) == s->group_size && bottom != 1)
			bottom--;
	}
}
