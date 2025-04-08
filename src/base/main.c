/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/08 14:00:52 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

inline static void	handle_token_syntax_error(t_minishell *ms)
{
	printf("Token Syntax error\n");
	free_token(ms->token);
	ms->token = NULL;
}

inline static void	handle_expression_syntax_error(t_minishell *ms)
{
	printf("Expression Syntax error\n");
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}

static char	*get_path(char *relative_path)
{
	char	*absolute_path = NULL;
	char	*resolved_path = NULL;
	char	cwd[PATH_MAX];

	if (relative_path[0] == '/')
		return (ft_strdup(relative_path));
	if (ft_strchr(relative_path, '/'))
	{
		resolved_path = malloc(PATH_MAX);
		if (!resolved_path)
			return (NULL);
		if (realpath(relative_path, resolved_path))
			return (resolved_path);
		free(resolved_path);
		return (NULL);
	}
	char *path_env = getenv("PATH");
	if (path_env)
	{
		char *path_copy = ft_strdup(path_env);
		char *path_token = strtok(path_copy, ":");
		
		while (path_token)
		{
			char test_path[PATH_MAX];
			ft_strlcpy(test_path, path_token, PATH_MAX);
			ft_strlcat(test_path, "/", PATH_MAX);
			ft_strlcat(test_path, relative_path, PATH_MAX);
			if (access(test_path, X_OK) == 0)
			{
				absolute_path = ft_strdup(test_path);
				free(path_copy);
				return (absolute_path);
			}
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
	}
	if (getcwd(cwd, PATH_MAX))
	{
		absolute_path = malloc(PATH_MAX);
		if (!absolute_path)
			return (NULL);
		ft_strlcpy(absolute_path, cwd, PATH_MAX);
		ft_strlcat(absolute_path, "/", PATH_MAX);
		ft_strlcat(absolute_path, relative_path, PATH_MAX);
		return (absolute_path);
	}
	return (ft_strdup(relative_path));
}

/*
	- manages ms.token and ms.expr
		=> needs to also free them
*/
static void	handle_input(t_minishell *ms)
{
	ms->token = parse_token(ms->input);
	if (!ms->token)
		return (free_minishell(ms), exit(EXIT_FAILURE));
	if (token_has_syntax_error(ms->token))
	{
		handle_token_syntax_error(ms);
		return ;
	}
	ms->expr = parse_expression(ms->token, NULL, ms->env);
	if (!ms->expr)
		return (free_minishell(ms), exit(EXIT_FAILURE));
	if (expression_has_syntax_error(ms->expr))
	{
		handle_expression_syntax_error(ms);
		return ;
	}
	execute_minishell(ms);
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}

/*
	- manages ms.input and ms.env
		=> needs to also free it
*/
int	main(int argc, char **argv, char **envp)
{
	t_minishell	ms;
	char		*path;

	(void)argc;
	(void)argv;
	path = get_path(argv[0]);
	if (!path)
		path = argv[0];
	setup_interactive();
	init_minishell(&ms, envp, path);
	if (path != argv[0])
		free(path);
	while (1)
	{
		ms.input = balance_input();
		if (!ms.input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		handle_input(&ms);
		add_history(ms.input);
		free(ms.input);
		ms.input = NULL;
	}
	return (free_minishell(&ms), EXIT_SUCCESS);
}
