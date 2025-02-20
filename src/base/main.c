/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/20 11:01:57 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//t_command *create_test_command()
//{
//    t_command *command;

//    command = (t_command *)malloc(sizeof(t_command));
//    if (!command)
//        return (NULL);

//    // Allocate memory for args array
//    command->args = (char **)malloc(sizeof(char *) * 3);  // Space for command and NULL
//    if (!command->args)
//    {
//        free(command);
//        return (NULL);
//    }

//    command->cmd = "cd";
//    command->args[0] = "...";
//    command->args[1] = NULL;
//    command->infile = NULL;
//    command->outfile = NULL;
//    command->append = false;
//    command->pipe = false;
//    command->background = false;
//    command->next = NULL;

//    return (command);
//}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_token			*token;
	t_expression	*expr;
	t_env			*env;

	env = init_env(envp);
	input = readline(PROMPT);
	while (input)
	{
		if (*input)
		{
			token = parse_token(input);
			if (token == NULL)
			{
				free_token(token);
				return (0);
			}
			expr = parse_expression(token, NULL);
			if (expr == NULL)
			{
				free_token(token);
				free_expression(expr);
				return (0);
			}
			execute(expr, env);
			add_history(input);
		}
		free(input);
		input = readline(PROMPT);
	}
	free_token(token);
	free_expression(expr);
	// atexit(leaks_end);
	return (0);
*/
