/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:08:04 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/28 12:17:52 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	init_shell(t_env **env, char **envp)
{
	*env = init_env(envp);
	if (!*env)
	{
		free_env(env);
		return (FAILURE);
	}
	handle_lvl(env);
	return (SUCCESS);
}

void	handle_lvl(t_env **env)
{
	char	*lvl_str;
	char	*new_lvl;
	int		lvl;

	lvl_str = get_env_value(*env, "SHLVL");
	if (!lvl_str || !*lvl_str)
		lvl = 1;
	else
	{
		lvl + ft_atoi(lvl_str);
		if (lvl < 0)
			lvl = 0;
		else if (lvl >= 999)
		{
			ft_putstr_fd("minishell: warning: shell level(", 2);
			ft_putnbr_fd(lvl + 1, 2);
			ft_putstr_fd(") too high, resetting to 1\n", 2);
			lvl = 1;
		}
		else
			lvl ++;
		new_lvl = ft_itoa(lvl);
		set_env_val(env, "SHLVL", new_lvl);
	}
}