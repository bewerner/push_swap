/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:25:38 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 23:35:32 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	map_to_sorted_index(int j, int i, t_push_swap *s)
{
	while (i <= s->size_a)
	{
		if (s->b[i] < s->b[i - 1])
		{
			s->b[0] = s->b[i - 1];
			s->b[i - 1] = s->b[i];
			s->b[i] = s->b[0];
			i = 1;
		}
		i++;
	}
	i = 1;
	j = 1;
	while (i <= s->size_a)
	{
		if (s->a[i] == s->b[j])
		{
			s->a[i] = j;
			i++;
			j = 0;
		}
		j++;
	}
}

void	init_stacks(t_push_swap *s, char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	s->initial_size = i;
	s->size_a = i;
	s->size_b = 0;
	s->a = (int *)ft_calloc(s->size_a + 2, sizeof(int));
	s->b = (int *)ft_calloc(s->size_a + 2, sizeof(int));
	s->cost = (int *)ft_calloc(s->size_a + 2, sizeof(int));
	if (!s->a || !s->b || !s->cost)
		put_error("Error: Memory allocation failed!\n", argv, s);
	i = 0;
	while (argv[i] != NULL)
	{
		validate(argv[i], argv, i, s);
		s->a[i + 1] = ft_atoi(argv[i]);
		s->b[i + 1] = s->a[i + 1];
		i++;
	}
	free_argv(argv, s);
	map_to_sorted_index(1, 2, s);
}

void	push_swap(t_push_swap *s, char **argv)
{
	if (!argv)
		put_error("Error: Memory allocation failed!\n", argv, s);
	init_stacks(s, argv);
	presort(s);
	sort_three(s);
	final_sort(s);
}

void	whitespace_to_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	s;

	s.argc = argc;
	s.cost = NULL;
	s.a = NULL;
	s.b = NULL;
	if (argc > 2)
		push_swap(&s, argv + 1);
	if (argc == 2)
	{
		whitespace_to_space(argv[1]);
		push_swap(&s, ft_split(argv[1], ' '));
	}
	free_stacks(&s);
	return (0);
}
