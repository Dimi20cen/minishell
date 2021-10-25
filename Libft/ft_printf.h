/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:16:38 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/22 12:10:52 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char c, int *chars_printed);

void	ft_putstr(char *s, int *chars_printed);

void	ft_putnbr(int n, int *chars_printed);

void	ft_putnbr_sb(unsigned int n, int *chars_printed, int s_or_b);

void	ft_put_p(unsigned long n, int *chars_printed);

void	ft_putnbr_for_u(unsigned int n, int *chars_printed);

void	foo(const char *input, va_list vars, int *chars_printed);

int		ft_printf(const char *input, ...);

#endif