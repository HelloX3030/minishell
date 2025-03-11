/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:08:04 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 10:26:23 by lkubler          ###   ########.fr       */
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

static void	child_process(char **args, char **envp)
{
	execve("./minishell", args, envp);
	perror("minishell");
	free_array(envp);
	exit(1);
}

static int	handle_parent(pid_t pid, char **envp)
{
	int	status;

	waitpid(pid, &status, 0);
	free_array(envp);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (SUCCESS);
}

int	exec_shell(char **args, t_env *env)
{
	pid_t	pid;
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
		child_process(args, envp);
	return (handle_parent(pid, envp));
}
