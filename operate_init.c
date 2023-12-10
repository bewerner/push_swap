/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:25:38 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:25:47 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate(char *instruction, t_push_swap *s)
{
	if (instruction[0] == 's')
		op_swap(instruction, s);
	if (instruction[0] == 'p' && instruction[1] == 'a')
		op_push_a(s);
	if (instruction[0] == 'p' && instruction[1] == 'b')
		op_push_b(s);
	if (instruction[0] == 'r' && instruction[2] == '\0')
		op_shift_up(instruction, s);
	if (instruction[0] == 'r' && instruction[2] != '\0')
		op_shift_down(instruction, s);
	ft_printf("%s\n", instruction);
	s->instruction_count++;
}
