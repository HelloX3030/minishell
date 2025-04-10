/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 15:01:59 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/*
	- manages ms.token and ms.expr
		=> needs to also free them
*/
static void	handle_input(t_minishell *ms)
{
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

	(void)argc;
	(void)argv;
	setup_interactive();
	init_minishell(&ms, envp);
	while (1)
	{
		if (get_input(&ms) == EXIT_FAILURE)
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
