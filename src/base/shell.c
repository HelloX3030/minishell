/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:08:04 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/03 13:43:18 by lseeger          ###   ########.fr       */
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
	ft_free_strs(envp);
	exit(1);
}

static int	handle_parent(pid_t pid, char **envp)
{
	int	status;

	waitpid(pid, &status, 0);
	ft_free_strs(envp);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (SUCCESS);
}

int	exec_shell(char **args, t_minishell *ms)
{
	pid_t	pid;
	char	**envp;

	envp = env_to_array(ms->env);
	if (!envp)
	{
		ft_free_strs(envp);
		return (FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_free_strs(envp);
		return (FAILURE);
	}
	if (pid == 0)
		child_process(args, envp);
	return (handle_parent(pid, envp));
}
