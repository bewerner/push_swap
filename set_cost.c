/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:34:02 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:41:27 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_to_top_cost(int i_a, int i_b, t_push_swap *s)
{
	int	cheapest;
	int	a_up;
	int	a_dn;
	int	b_up;
	int	b_dn;

	a_up = i_a - 1;
	b_up = i_b - 1;
	a_dn = s->size_a - i_a + 1;
	b_dn = s->size_b - i_b + 1;
	cheapest = a_up + b_dn;
	if (a_dn + b_up < cheapest)
		cheapest = a_dn + b_up;
	if (a_up >= b_up && a_up < cheapest)
		cheapest = a_up;
	if (b_up >= a_up && b_up < cheapest)
		cheapest = b_up;
	if (a_dn >= b_dn && a_dn < cheapest)
		cheapest = a_dn;
	if (b_dn >= a_dn && b_dn < cheapest)
		cheapest = b_dn;
	return (cheapest);
}

void	set_cost(t_push_swap *s)
{
	int	i;
	int	i_target;

	i = 1;
	while (i <= s->size_b)
	{
		i_target = get_i_of_target(i, s);
		s->cost[i] = rotate_to_top_cost(i_target, i, s) + 1;
		i++;
	}
}
