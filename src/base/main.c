/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 12:20:33 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


t_command *create_test_command()
{
    t_command *command;

    command = (t_command *)malloc(sizeof(t_command));
    if (!command)
        return (NULL);

    // Allocate memory for args array
    command->args = (char **)malloc(sizeof(char *) * 2);  // Space for command and NULL
    if (!command->args)
    {
        free(command);
        return (NULL);
    }

    command->cmd = "ls";
    command->args[0] = "";
    command->args[1] = NULL;
    command->infile = NULL;
    command->outfile = NULL;
    command->append = false;
    command->pipe = false;
    command->background = false;
    command->next = NULL;

    return (command);
}

int main(int argc, char **argv, char **envp)
{
    t_command *command;
    t_env *env;

    (void)argc;
    (void)argv;

    env = init_env(envp);
    if (!env)
        return (1);
	command = create_test_command();
    execute(command, env);
    rl_clear_history();
    // Free environment
    while (env)
    {
        t_env *tmp = env;
        env = env->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }

    return (0);
}
