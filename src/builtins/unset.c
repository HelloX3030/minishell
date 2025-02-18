/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:18:43 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/18 14:58:59 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_valid_id(const char *str)
{
	int	i;
	
	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalpha(str[0]) && str[0] != '_')
			return (0);
		i ++;
	}
	return (1);
}

int	mini_unset(char **args, t_env **env)
{
	int	i;
	
	if (!args[1])
		return (1);
	i = 1;
	while (args[i])
	{
		if(is_valid_id(args[i]))
			unset_env_val(env, args[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i ++;
	}
	return (0);
}