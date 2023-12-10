/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:18:20 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/11 04:42:48 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	reset_s_and_set_con(const char *str, int j, char *cons, t_printf *s)
{
	s->f_hash = 0;
	s->f_space = 0;
	s->f_plus = 0;
	s->f_minus = 0;
	s->f_zero = 0;
	s->f_dot = 0;
	s->len_mfw = 0;
	s->len_front_pad = 0;
	s->len_back_pad = 0;
	s->len_con = 0;
	s->len_prefix = 0;
	s->len_precision = 0;
	s->len_precede = 0;
	s->len_body = 0;
	while (str[s->i] != cons[j])
	{
		s->i++;
		j = 0;
		while (str[s->i] != cons[j] && cons[j] != '\0')
			j++;
	}
	s->con = cons[j];
	if (s->con == 'i')
		s->con = 'd';
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_printf	s;

	va_start(args, str);
	s.i = 0;
	s.count = 0;
	while (str[s.i] != '\0')
	{
		if (str[s.i] == '%')
		{
			reset_s_and_set_con(str, 0, "cspdiuxX%", &s);
			if (s.con == '%')
			{
				s.con = 'c';
				ftprintf_con_init(str, (void *) '%', &s);
			}
			else
				ftprintf_con_init(str, va_arg(args, void *), &s);
		}
		else
			ftprintf_putchar(str[s.i], &s);
		s.i++;
	}
	va_end(args);
	return (s.count);
}
