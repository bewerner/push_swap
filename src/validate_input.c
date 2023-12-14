/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:26:21 by bwerner           #+#    #+#             */
/*   Updated: 2023/12/10 22:29:08 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(int n, int i, t_push_swap *s)
{
	while (i > 0)
	{
		if (n == s->a[i])
			return (0);
		i--;
	}
	return (1);
}

int	is_in_range(char *nbstr, char *min, char *max)
{
	int		nbstrlen;
	int		i;

	nbstrlen = ft_strlen(nbstr);
	if ((nbstrlen > 11) || (nbstrlen > 10 && nbstr[0] != '-'))
		return (0);
	i = 0;
	while (nbstr[i] != '\0' && nbstrlen == 10 && nbstr[0] != '-')
	{
		if (nbstr[i] < max[i])
			return (1);
		if (nbstr[i] > max[i])
			return (0);
		i++;
	}
	i = 1;
	while (nbstr[i] != '\0' && nbstrlen == 11 && nbstr[0] == '-')
	{
		if (nbstr[i] < min[i])
			return (1);
		if (nbstr[i] > min[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate(char *str, char **argv, int i, t_push_swap *s)
{
	if (!is_numeric(str))
		put_error("Error\n", argv, s);
	if (!is_in_range(str, "-2147483648", "2147483647"))
		put_error("Error\n", argv, s);
	if (!is_unique(ft_atoi(str), i, s))
		put_error("Error\n", argv, s);
}
