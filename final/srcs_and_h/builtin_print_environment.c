/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_print_environment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:36:03 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:36:04 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_environment(t_hashmap *env, int fd)
{
	char	**env_array;

	env_array = hashmap_to_env(env);
	print_2d_array_fd(env_array, fd);
	free_2d_array(env_array);
	g_minishell.error_status = 0;
}
