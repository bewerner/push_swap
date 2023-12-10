/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:36:35 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:36:52 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_b(int a, int b, t_push_swap *s)
{
	while (a || b)
	{
		if (a > 0 && b > 0)
			operate("rr", s);
		if (a < 0 && b < 0)
			operate("rrr", s);
		if (a > 0 && b <= 0)
			operate("ra", s);
		if (a < 0 && b >= 0)
			operate("rra", s);
		if (b > 0 && a <= 0)
			operate("rb", s);
		if (b < 0 && a >= 0)
			operate("rrb", s);
		if (a > 0)
			a--;
		if (a < 0)
			a++;
		if (b > 0)
			b--;
		if (b < 0)
			b++;
	}
}

void	rotate_to_top(int i_a, int i_b, t_push_swap *s)
{
	int	a_up;
	int	a_dn;
	int	b_up;
	int	b_dn;
	int	cost;

	a_up = i_a - 1;
	b_up = i_b - 1;
	a_dn = s->size_a - i_a + 1;
	b_dn = s->size_b - i_b + 1;
	cost = rotate_to_top_cost(i_a, i_b, s);
	if (a_up + b_dn == cost)
		rotate_a_b(a_up, b_dn * -1, s);
	else if (a_dn + b_up == cost)
		rotate_a_b(a_dn * -1, b_up, s);
	else if (a_up == cost || b_up == cost)
		rotate_a_b(a_up, b_up, s);
	else if (a_dn == cost || b_dn == cost)
		rotate_a_b(a_dn * -1, b_dn * -1, s);
}
