/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:48 by bwerner           #+#    #+#             */
/*   Updated: 2023/10/12 17:08:51 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*jstr;

	i = 0;
	jstr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (jstr == 0)
		return (0);
	ft_strlcpy(jstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(jstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (jstr);
}
