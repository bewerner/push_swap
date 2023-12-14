/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:35:04 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:35:59 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max_a(t_push_swap *s)
{
	int	i;

	i = 2;
	s->max_a = s->a[1];
	s->max_a_i = 1;
	s->min_a = s->a[1];
	s->min_a_i = 1;
	while (i <= s->size_a)
	{
		if (s->a[i] > s->max_a)
		{
			s->max_a = s->a[i];
			s->max_a_i = i;
		}
		if (s->a[i] < s->min_a)
		{
			s->min_a = s->a[i];
			s->min_a_i = i;
		}
		i++;
	}
}

int	a_is_sorted(t_push_swap *s)
{
	int	i;

	set_min_max_a(s);
	i = s->min_a_i + 1;
	if (i > s->size_a)
		i = 1;
	while (i != s->min_a_i)
	{
		if (i == 1 && s->a[i] > s->a[s->size_a])
			i++;
		else if (i != 1 && s->a[i] > s->a[i - 1])
			i++;
		else
			return (0);
		if (i > s->size_a)
			i = 1;
	}
	return (1);
}

void	sort_three(t_push_swap *s)
{
	if (a_is_sorted(s))
		return ;
	if (s->a[1] > s->a[2] && s->a[1] > s->a[3])
		operate("ra", s);
	if (s->a[2] > s->a[3] && s->a[2] > s->a[1])
		operate("rra", s);
	if (s->a[1] > s->a[2])
		operate("sa", s);
}
