/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:35:03 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/25 11:53:25 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_sb(unsigned int n, int *chars_printed, int s_or_b)
{
	if (n > 15)
		ft_putnbr_sb(n / 16, chars_printed, s_or_b);
	if (n % 16 > 9)
	{
		if (s_or_b == 's')
			ft_putchar((n % 16) + 87, chars_printed);
		else
			ft_putchar((n % 16) + 55, chars_printed);
	}
	else
		ft_putchar((n % 16) + '0', chars_printed);
}

void	ft_put_p(unsigned long n, int *chars_printed)
{
	if (n > 15)
		ft_put_p(n / 16, chars_printed);
	if (n % 16 > 9)
		ft_putchar((n % 16) + 87, chars_printed);
	else
		ft_putchar((n % 16) + '0', chars_printed);
}

void	ft_putnbr_for_u(unsigned int n, int *chars_printed)
{
	if (n > 9)
		ft_putnbr(n / 10, chars_printed);
	ft_putchar((n % 10) + '0', chars_printed);
}

void	foo(const char *input, va_list vars, int *chars_printed)
{
	if (*input == 'c')
		ft_putchar(va_arg(vars, int), chars_printed);
	else if (*input == 's')
		ft_putstr(va_arg(vars, char *), chars_printed);
	else if (*input == 'p')
	{
		ft_putchar('0', chars_printed);
		ft_putchar('x', chars_printed);
		ft_put_p(va_arg(vars, unsigned long int), chars_printed);
	}
	else if (*input == 'd' || *input == 'i')
		ft_putnbr(va_arg(vars, int), chars_printed);
	else if (*input == 'u')
		ft_putnbr_for_u(va_arg(vars, unsigned int), chars_printed);
	else if (*input == 'x')
		ft_putnbr_sb(va_arg(vars, unsigned int), chars_printed, 's');
	else if (*input == 'X')
		ft_putnbr_sb(va_arg(vars, unsigned int), chars_printed, 'b');
	else if (*input == '%')
		ft_putchar('%', chars_printed);
}

int	ft_printf(const char *input, ...)
{
	int		chars_printed;
	va_list	vars;	

	chars_printed = 0;
	va_start(vars, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			foo(input, vars, &chars_printed);
		}
		else
			ft_putchar(*input, &chars_printed);
		input++;
	}
	va_end(vars);
	return (chars_printed);
}
