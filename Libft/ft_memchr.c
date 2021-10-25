/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:07:21 by dmylonas          #+#    #+#             */
/*   Updated: 2021/08/18 13:10:53 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	new_c;
	size_t			i;

	new_c = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == new_c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
