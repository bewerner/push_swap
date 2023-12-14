/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:29:27 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:41:24 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv, t_push_swap *s)
{
	int	i;

	i = 0;
	if (s->argc == 2 && argv)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

void	free_stacks(t_push_swap *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	if (s->cost)
		free(s->cost);
}

void	put_error(char *error_message, char **argv, t_push_swap *s)
{
	free_stacks(s);
	free_argv(argv, s);
	write(2, error_message, ft_strlen(error_message));
	exit (1);
}
