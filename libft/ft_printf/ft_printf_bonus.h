/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:38 by bwerner           #+#    #+#             */
/*   Updated: 2023/11/16 17:20:17 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_printf
{
	int		i;
	int		count;
	char	con;
	int		f_hash;
	int		f_space;
	int		f_plus;
	int		f_minus;
	int		f_zero;
	int		f_dot;
	int		len_mfw;
	int		len_front_pad;
	int		len_back_pad;
	int		len_con;
	int		len_prefix;
	int		len_precision;
	int		len_precede;
	int		len_body;
}		t_printf;

int		ft_printf(const char *input, ...);
void	ftprintf_con_init(const char *str, void *arg, t_printf *s);
void	ftprintf_set_s(const char *str, int i, void *arg, t_printf *s);
void	ftprintf_set_len_con(void *arg, t_printf *s);
void	ftprintf_putchar(char c, t_printf *s);

#endif
