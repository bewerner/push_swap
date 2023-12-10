/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:49:50 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/11 04:42:45 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ftprintf_putchar(char c, t_printf *s)
{
	if (s->count != -1 && write(1, &c, 1) != -1)
		s->count++;
	else
		s->count = -1;
}
