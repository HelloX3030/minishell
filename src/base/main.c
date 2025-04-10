/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 15:51:30 by lkubler          ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:05:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 17:05:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	display_welcome(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_putstr_fd("\033[1;36m", STDOUT_FILENO);
	ft_putstr_fd(" __  __ _____ _   _ _____  _____ _    _ ______ _      _      \n", STDOUT_FILENO);
	ft_putstr_fd("|  \\/  |_   _| \\ | |_   _|/ ____| |  | |  ____| |    | |     \n", STDOUT_FILENO);
	ft_putstr_fd("| \\  / | | | |  \\| | | | | (___ | |__| | |__  | |    | |     \n", STDOUT_FILENO);
	ft_putstr_fd("| |\\/| | | | | . ` | | |  \\___ \\|  __  |  __| | |    | |     \n", STDOUT_FILENO);
	ft_putstr_fd("| |  | |_| |_| |\\  |_| |_ ____) | |  | | |____| |____| |____ \n", STDOUT_FILENO);
	ft_putstr_fd("|_|  |_|_____|_| \\_|_____|_____/|_|  |_|______|______|______|\n", STDOUT_FILENO);
	ft_putstr_fd("\033[0m\n", STDOUT_FILENO);
}

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
