/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:05:06 by dmylonas          #+#    #+#             */
/*   Updated: 2021/08/08 18:48:20 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*new_src;

	new_src = src;
	while (n--)
	{
		*(char *)dest = *new_src;
		if (*new_src == c)
		{
			dest++;
			return (dest);
		}
		dest++;
		new_src++;
	}
	return (0);
}
// int		main(void)
// {
// 	char dest[30] = "asdfghjkl";
// 	char src[30] = "0123456789";
// 	int c = 51;
// 	size_t n = 6;	
// 	ft_memccpy(dest, src, c, n);
// 	printf("%s\n", (char *)(ft_memccpy(dest, src, c, n)));
// 	printf("%s\n", (char *)(memccpy(dest, src, c, n)));
// }

