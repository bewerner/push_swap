/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_s_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:49:55 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/11 04:42:46 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	set_len_padding(t_printf *s)
{
	if (s->f_space && !s->len_precede)
		s->len_front_pad = 1;
	if (s->f_zero && s->len_mfw > s->len_body + s->len_front_pad)
		s->len_prefix += s->len_mfw - s->len_body - s->len_front_pad;
	s->len_body = s->len_precede + s->len_prefix + s->len_con;
	if (s->f_minus)
		s->len_back_pad = s->len_mfw - (s->len_body + s->len_front_pad);
	else
		s->len_front_pad = s->len_mfw - (s->len_body + s->len_front_pad);
	if (s->f_space && !s->len_precede)
		s->len_front_pad = 1;
	if (s->len_mfw > s->len_body + s->len_front_pad + s->len_back_pad)
	{
		if (s->f_minus)
			s->len_back_pad = s->len_mfw - (s->len_body + s->len_front_pad);
		else
			s->len_front_pad = s->len_mfw - s->len_body;
	}
}

static void	set_len_mfw(const char *str, int i, t_printf *s)
{
	int	x;

	x = 1;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '%')
		i--;
	while (str[i] >= '0' && str[i] <= '9')
		i--;
	if (str[i] == '.')
	{
		set_len_mfw(str, i, s);
		return ;
	}
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		s->len_mfw += (str[i] - '0') * x;
		x *= 10;
		i--;
	}
	if (s->len_mfw == 0 && str[i] != '%')
		set_len_mfw(str, i, s);
}

static void	set_len_precision(const char *str, int i, t_printf *s)
{
	int	x;

	x = 1;
	while (str[i] != '%' && str[i] != '.')
		i--;
	if (str[i] != '.')
		return ;
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] != '.')
	{
		s->len_precision += (str[i] - '0') * x;
		x *= 10;
		i--;
	}
}

static void	set_flags(const char *str, int i, void *arg, t_printf *s)
{
	while (str[i] != '%')
	{
		if (str[i] == '+' && s->con == 'd')
			s->f_plus = 1;
		if (str[i] == ' ' && s->con == 'd')
			s->f_space = 1;
		if (str[i] == '#' && (s->con == 'x' || s->con == 'X'))
			if ((unsigned int)arg != 0)
				s->f_hash = 1;
		if (str[i] == '.' && s->con != 'c')
			s->f_dot = 1;
		if (str[i] == '-')
			s->f_minus = 1;
		if (str[i] == '0' && str[i - 1] != '.')
			if (str[i - 1] < '0' || str[i - 1] > '9')
				s->f_zero = 1;
		i--;
	}
	if (s->f_plus || (s-> con == 'd' && (int)arg < 0))
		s->f_space = 0;
	if (s->f_dot && s->con != 'c' && s->con != 's')
		s->f_zero = 0;
	if (s->f_minus)
		s->f_zero = 0;
}

void	ftprintf_set_s(const char *str, int i, void *arg, t_printf *s)
{
	set_flags(str, i, arg, s);
	set_len_precision(str, i, s);
	set_len_mfw(str, i, s);
	if (!s->len_mfw)
		s->f_zero = 0;
	ftprintf_set_len_con(arg, s);
	if (s->con != 'c' && s->con != 's' && s->len_precision > s->len_con)
		s->len_prefix = s->len_precision - s->len_con;
	if (s->f_plus || (s-> con == 'd' && (int)arg < 0))
		s->len_precede = 1;
	if (s->con == 'p' || (s->f_hash && (unsigned int)arg != 0))
		s->len_precede = 2;
	s->len_body = s->len_precede + s->len_prefix + s->len_con;
	set_len_padding(s);
}
