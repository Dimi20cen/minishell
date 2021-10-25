/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:17:37 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/22 12:22:28 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *chars_printed)
{
	write(1, &c, 1);
	*chars_printed += 1;
}

void	ft_putstr(char *s, int *chars_printed)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, chars_printed);
		s++;
	}
}

void	ft_putnbr(int n, int *chars_printed)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", chars_printed);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', chars_printed);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr(n / 10, chars_printed);
		ft_putchar((n % 10) + '0', chars_printed);
	}
}
