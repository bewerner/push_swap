/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:56:18 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:25:33 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_shift_down(char *instruction, t_push_swap *s)
{
	int	i;

	if (instruction[2] == 'a' || instruction[2] == 'r')
	{
		i = s->size_a;
		s->a[0] = s->a[s->size_a];
		while (i >= 1)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
	}
	if (instruction[2] == 'b' || instruction[2] == 'r')
	{
		i = s->size_b;
		s->b[0] = s->b[s->size_b];
		while (i >= 1)
		{
			s->b[i] = s->b[i - 1];
			i--;
		}
	}
}

void	op_shift_up(char *instruction, t_push_swap *s)
{
	int	i;

	if (instruction[1] == 'a' || instruction[1] == 'r')
	{
		i = 1;
		s->a[s->size_a + 1] = s->a[1];
		while (i <= s->size_a)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
	}
	if (instruction[1] == 'b' || instruction[1] == 'r')
	{
		i = 1;
		s->b[s->size_b + 1] = s->b[1];
		while (i <= s->size_b)
		{
			s->b[i] = s->b[i + 1];
			i++;
		}
	}
}

void	op_push_b(t_push_swap *s)
{
	int	i;

	s->size_b++;
	s->b[0] = s->a[1];
	i = s->size_b;
	while (i >= 1)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	i = 1;
	while (i <= s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->size_a--;
}

void	op_push_a(t_push_swap *s)
{
	int	i;

	s->size_a++;
	s->a[0] = s->b[1];
	i = s->size_a;
	while (i >= 1)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	i = 1;
	while (i <= s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->size_b--;
}

void	op_swap(char *instruction, t_push_swap *s)
{
	if (instruction[1] == 'a' || instruction[1] == 's')
	{
		s->a[0] = s->a[1];
		s->a[1] = s->a[2];
		s->a[2] = s->a[0];
	}
	if (instruction[1] == 'b' || instruction[1] == 's')
	{
		s->b[0] = s->b[1];
		s->b[1] = s->b[2];
		s->b[2] = s->b[0];
	}
}
