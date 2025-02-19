/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 10:46:06 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


t_command *create_test_command(char **args)
{
    t_command *command;

    // Allocate memory for command structure
    command = (t_command *)malloc(sizeof(t_command));
    if (!command)
        return (NULL);

    // Initialize all fields to default values
    command->cmd = "env";
    command->args = args;
    command->infile = NULL;
    command->outfile = NULL;
    command->append = false;
    command->pipe = false;
    command->background = false;
    command->next = NULL;

    return (command);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	(void) argc;
	t_command *command;
	command = create_test_command(argv);
	t_env *env = init_env(envp);
	input = readline(PROMPT);
	execute(command, env);
	//while (input)
	//{
	//	if (*input)
	//		add_history(input);
	//	if (strcmp(input, "exit") == 0)
	//	{
	//		free(input);
	//		break ;
	//	}
	//	printf("You typed: %s\n", input);
	//	free(input);
	//	input = readline(PROMPT);
	//}
	//rl_clear_history();
	return (0);
}
