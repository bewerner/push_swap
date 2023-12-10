/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_con_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:49:58 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/11 04:42:47 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	put_nbr_con(long int n, size_t base, char *basestr, t_printf *s)
{
	if (n < 0 && base == 10)
		n = n * -1;
	if ((unsigned long int)n >= base)
	{
		put_nbr_con((unsigned long int)n / base, base, basestr, s);
		n = (unsigned long int)n % base;
	}
	ftprintf_putchar(basestr[n], s);
}

static void	put_str_len(const char *str, int len, t_printf *s)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		put_str_len("(null)", len, s);
		return ;
	}
	while (i < len)
	{
		ftprintf_putchar(str[i], s);
		i++;
	}
}

static void	put_precede(void *arg, t_printf *s)
{
	if (s->len_precede == 1 && s->con == 'd')
	{
		if ((int)arg < 0)
			ftprintf_putchar('-', s);
		else
			ftprintf_putchar('+', s);
	}
	if (s->len_precede == 2 && s->con == 'p')
		put_str_len("0x", 2, s);
	if (s->len_precede == 2 && s->f_hash && s->con == 'x')
		put_str_len("0x", 2, s);
	if (s->len_precede == 2 && s->f_hash && s->con == 'X')
		put_str_len("0X", 2, s);
}

static void	put_n_chars(int n, char c, t_printf *s)
{
	while (n > 0)
	{
		ftprintf_putchar(c, s);
		n--;
	}
}

void	ftprintf_con_init(const char *str, void *arg, t_printf *s)
{
	ftprintf_set_s(str, s->i - 1, arg, s);
	put_n_chars(s->len_front_pad, ' ', s);
	put_precede(arg, s);
	put_n_chars(s->len_prefix, '0', s);
	if (s->con == 'c')
		ftprintf_putchar((char)arg, s);
	if (s->con == 's')
		put_str_len((char *)arg, s->len_con, s);
	if (s->con == 'p' && s->len_con != 0)
		put_nbr_con((unsigned long int)arg, 16, "0123456789abcdef", s);
	if (s->con == 'd' && s->len_con != 0)
		put_nbr_con((int)arg, 10, "0123456789", s);
	if (s->con == 'u' && s->len_con != 0)
		put_nbr_con((unsigned int)arg, 10, "0123456789", s);
	if (s->con == 'x' && s->len_con != 0)
		put_nbr_con((unsigned int)arg, 16, "0123456789abcdef", s);
	if (s->con == 'X' && s->len_con != 0)
		put_nbr_con((unsigned int)arg, 16, "0123456789ABCDEF", s);
	put_n_chars(s->len_back_pad, ' ', s);
}
