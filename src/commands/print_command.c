/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:54 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/17 15:44:31 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_args(t_command *cmd, int insertion)
{
	int		i;
	char	*insertion_str;

	insertion_str = ft_get_insertion(insertion);
	i = 0;
	while (cmd->args + i)
	{
		printf("%s%s", insertion_str, cmd->args[i]);
		i++;
	}
	free(insertion_str);
}

static void	print_file_info(t_command *cmd, char *large_insertion_str)
{
	if (cmd->infile)
		printf("%sinfile: %s\n", large_insertion_str, cmd->infile);
	if (cmd->outfile)
		printf("%soutfile: %s\n", large_insertion_str, cmd->outfile);
	if (cmd->append)
		printf("%sappend: true\n", large_insertion_str);
}

void	print_command(t_command *cmd, int insertion)
{
	char	*insertion_str;
	char	*large_insertion_str;

	insertion_str = ft_get_insertion(insertion);
	large_insertion_str = ft_get_insertion(insertion + 1);
	printf("%scommand: ", insertion_str);
	if (cmd)
		printf("%s\n", cmd->cmd);
	else
		printf("NULL\n");
	if (cmd->args)
	{
		printf("%sargs: \n", large_insertion_str);
		print_args(cmd, insertion + 2);
	}
	print_file_info(cmd, large_insertion_str);
	if (cmd->pipe)
	{
		printf("%spipe: true\n", large_insertion_str);
		print_command(cmd->pipe, insertion);
	}
	free(insertion_str);
	free(large_insertion_str);
}
