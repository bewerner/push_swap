/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:04:42 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/12 07:50:02 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	put_error_bonus(char *error_message, t_push_swap *s)
{
	free_stacks(s);
	write(2, error_message, ft_strlen(error_message));
	exit (1);
}

void	init_stacks_bonus(t_push_swap *s, char **argv)
{
	int	i;

	if (!argv)
		put_error("Error: Memory allocation failed!\n", argv, s);
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

int	instruction_is_valid(char *instruction)
{
	if (!ft_strncmp(instruction, "sa\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "sb\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "ss\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "pa\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "pb\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "ra\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "rb\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "rr\0", 3))
		return (1);
	if (!ft_strncmp(instruction, "rra\0", 4))
		return (1);
	if (!ft_strncmp(instruction, "rrb\0", 4))
		return (1);
	if (!ft_strncmp(instruction, "rrr\0", 4))
		return (1);
	return (0);
}

void	read_instructions(t_push_swap *s)
{
	char	instruction[4];
	char	buf;
	int		i;

	i = 0;
	buf = '\n';
	while (read(0, &buf, 1))
	{
		if (i < 3)
			instruction[i] = buf;
		if (instruction[i] == '\n')
			instruction[i] = '\0';
		i++;
		if (buf == '\n')
		{
			if (instruction_is_valid(instruction))
				operate(instruction, s);
			else
				put_error_bonus("Error\n", s);
			i = 0;
		}
	}
	if (buf != '\n')
		put_error_bonus("Error\n", s);
}

int	main(int argc, char **argv)
{
	t_push_swap	s;

	s.argc = argc;
	s.cost = NULL;
	s.a = NULL;
	s.b = NULL;
	s.print_instructions = 0;
	if (argc < 2)
		return (0);
	if (argc > 2)
		init_stacks_bonus(&s, argv + 1);
	if (argc == 2)
	{
		whitespace_to_space(argv[1]);
		init_stacks_bonus(&s, ft_split(argv[1], ' '));
	}
	read_instructions(&s);
	if (a_is_sorted(&s) && s.min_a_i == 1 && !s.size_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&s);
	return (0);
}
