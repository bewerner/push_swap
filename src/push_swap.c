/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 07:22:01 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/12 07:22:30 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	s;

	s.argc = argc;
	s.cost = NULL;
	s.a = NULL;
	s.b = NULL;
	s.print_instructions = 1;
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
