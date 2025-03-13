/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:18:43 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 10:46:15 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_valid_id(const char *str)
{
	int	i;

	if (!str || !*str)
		return (FAILURE);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (FAILURE);
	i = 1;
	while (str[i])
	{
		if (!ft_isalpha(str[0]) && str[0] != '_')
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}

int	mini_unset(char **args, t_minishell *ms)
{
	int	i;

	if (!args[1])
		return (EXIT_FAILURE);
	i = 1;
	while (args[i])
	{
		if (is_valid_id(args[i]))
			unset_env_val(&ms->env, args[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (EXIT_FAILURE);
		}
		i ++;
	}
	return (EXIT_SUCCESS);
}
