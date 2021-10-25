/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:27:14 by dmylonas          #+#    #+#             */
/*   Updated: 2021/08/18 13:11:06 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*new_dest;
	const char	*new_src;
	size_t		i;

	new_dest = dest;
	new_src = src;
	if (src < dest)
	{
		while (n--)
			new_dest[n] = new_src[n];
	}
	else if (dest < src)
	{
		i = -1;
		while (++i < n)
			new_dest[i] = new_src[i];
	}
	return (dest);
}
