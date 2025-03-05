/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:08:04 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/05 13:44:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
		lvl = ft_atoi(lvl_str);
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
			lvl++;
		new_lvl = ft_itoa(lvl);
		set_env_val(env, "SHLVL", new_lvl);
	}
}

int	exec_shell(char **args, t_env *env)
{
	pid_t	pid;
	int		status;
	char	**envp;

	envp = env_to_array(env);
	if (!envp)
	{
		free_array(envp);
		return (FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		free_array(envp);
		return (FAILURE);
	}
	if (pid == 0)
	{
		execve("./minishell", args, envp);
		perror("minishell");
		free_array(envp);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free_array(envp);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (SUCCESS);
	}
}
