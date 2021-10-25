/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:43:22 by dmylonas          #+#    #+#             */
/*   Updated: 2021/08/18 13:32:11 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_until_stop(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

int	word_counter(char const *s, char c)
{
	int	found;
	int	i;
	int	count;

	found = 0;
	i = 0;
	count = 1;
	while (s[i])
	{
		if (found && s[i] != c)
		{
			found = 0;
			count++;
		}
		else if (s[i] == c)
			found = 1;
		i++;
	}
	return (count);
}

char	**splitter(char **splitted, const char *s, const char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len = len_until_stop(s, c);
			splitted[i] = (char *)ft_calloc(len + 1, sizeof(char));
			if (!splitted[i])
				return (NULL);
			ft_memcpy(splitted[i], s, len);
			s += len;
			i++;
		}
	}
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)ft_calloc(word_counter(s, c) + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted = splitter(splitted, s, c);
	return (splitted);
}
