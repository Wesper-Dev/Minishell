/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:24:57 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:24:58 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned int	pos;

	pos = 0;
	s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (pos < ft_strlen(s1))
	{
		s2[pos] = s1[pos];
		pos++;
	}
	s2[pos] = '\0';
	return (s2);
}
