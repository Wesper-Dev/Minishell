/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:09 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:25:10 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	if (n != 0)
	{
		pos = 0;
		while ((s1[pos] != '\0' || s2[pos] != '\0') && pos < n)
		{
			if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
				return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
			pos++;
		}
	}
	return (0);
}
