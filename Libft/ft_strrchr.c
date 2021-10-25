/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:50:54 by dmylonas          #+#    #+#             */
/*   Updated: 2021/08/18 13:12:09 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last_found;
	int	i;

	last_found = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			last_found = i;
		}
		i++;
	}
	if (last_found != -1)
		return ((char *)s + last_found);
	else if (c == '\0')
		return ((char *)s + i);
	else
		return (0);
}
