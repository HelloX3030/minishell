/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/11 17:16:49 by lkubler          ###   ########.fr       */
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

static void	display_welcome(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_putstr("\033[1;36m");
	ft_putstr(L1);
	ft_putstr(L2);
	ft_putstr(L3);
	ft_putstr(L4);
	ft_putstr(L5);
	ft_putstr(L6);
	ft_putstr("\033[38;2;64;224;208m");
	ft_putstr("Contributors:\n");
	ft_putstr(LSEEGER_GITHUB);
	ft_putstr(LKUBLER_GITHUB);
	ft_putstr("\033[0m\n");
}

/*
	- manages ms.input and ms.env
		=> needs to also free it
*/
int	main(int argc, char **argv, char **envp)
{
	t_minishell	ms;

	display_welcome(argc, argv);
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
