/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:54 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 14:00:18 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_args(t_command *cmd, int insertion)
{
	const char	*insertion_str = ft_get_insertion(insertion);
	int			i;

	i = 0;
	while (cmd->args + i)
	{
		printf("%s%s", insertion_str, cmd->args[i]);
		i++;
	}
	free(insertion_str);
}

void	print_command(t_command *cmd, int insertion)
{
	const char	*insertion_str = ft_get_insertion(insertion);

	printf("%scommand: \n", insertion_str);
	if (cmd->args)
	{
		printf("%sargs: \n", insertion_str);
		print_args(cmd, insertion + 1);
	}
	if (cmd->infile)
		printf("%sinfile: %s\n", insertion_str, cmd->infile);
	if (cmd->outfile)
		printf("%soutfile: %s\n", insertion_str, cmd->outfile);
	if (cmd->append)
		printf("%sappend: %s\n", insertion_str, cmd->append);
	if (cmd->pipe)
	{
		printf("%spipe: true\n", insertion_str);
		print_command(cmd->pipe, insertion + 1);
	}
}
