/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_len_con_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:49:53 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/11 04:42:46 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	set_nlen_con_base(long int n, size_t base, t_printf *s)
{
	if (n < 0 && base == 10)
		n = n * -1;
	if ((unsigned long int)n >= base)
	{
		set_nlen_con_base((unsigned long int)n / base, base, s);
		n = (unsigned long int)n % base;
	}
	s->len_con++;
}

static void	set_strlen_con(const char *str, t_printf *s)
{
	if (str == NULL)
	{
		set_strlen_con("(null)", s);
		return ;
	}
	if (s->f_dot)
		while (str[s->len_con] != '\0' && s->len_con < s->len_precision)
			s->len_con++;
	if (!s->f_dot)
		while (str[s->len_con] != '\0')
			s->len_con++;
}

void	ftprintf_set_len_con(void *arg, t_printf *s)
{
	if (s->con == 'c')
		s->len_con = 1;
	if (s->con == 'c' && s->f_dot && !s->len_precision)
		s->len_con = 0;
	if (s->con == 's')
		set_strlen_con((char *)arg, s);
	if (s->con == 'p')
		set_nlen_con_base((unsigned long int)arg, 16, s);
	if (s->con == 'd')
		set_nlen_con_base((int)arg, 10, s);
	if (s->con == 'u')
		set_nlen_con_base((unsigned int)arg, 10, s);
	if (s->con == 'x' || s->con == 'X')
		set_nlen_con_base((unsigned int)arg, 16, s);
	if (arg == 0 && s->f_dot && s->con != 's')
		s->len_con = 0;
}
