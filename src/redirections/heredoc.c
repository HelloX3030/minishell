/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:15:05 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/09 14:21:32 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	is_heredoc(char *file)
{
	return (ft_strncmp(file, "HEREDOC:", ft_strlen("HEREDOC:")) == 0);
}

static char	*get_delimiter(char *file)
{
	return (file + ft_strlen("HEREDOC:"));
}

static char	*get_temp_filename(void)
{
	static int	counter = 0;
	char		*filename;
	char		*num_str;

	num_str = ft_itoa(counter++);
	if (!num_str)
		return (NULL);
	filename = ft_strjoin("/tmp/minishell_heredoc_", num_str);
	free(num_str);
	return (filename);
}

static int	write_heredoc_content(int fd, char *delimiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = readline("");
		if (!line)
			return (EXIT_FAILURE);
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	return (EXIT_SUCCESS);
}

static int	handle_heredoc(t_expression *expr, char *delimiter)
{
	char	*temp_file;
	int		fd;
	int		result;

	temp_file = get_temp_filename();
	if (!temp_file)
		return (EXIT_FAILURE);
	fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		free(temp_file);
		return (EXIT_FAILURE);
	}
	result = write_heredoc_content(fd, delimiter);
	close(fd);
	if (result == EXIT_FAILURE)
	{
		unlink(temp_file);
		free(temp_file);
		return (EXIT_FAILURE);
	}
	if (save_fd(&expr->saved_stdin, STDIN_FILENO) == EXIT_FAILURE)
	{
		unlink(temp_file);
		free(temp_file);
		return (EXIT_FAILURE);
	}
	if (make_redir(STDIN_FILENO, temp_file, O_RDONLY) == EXIT_FAILURE)
	{
		unlink(temp_file);
		free(temp_file);
		restore_fd(&expr->saved_stdin, STDIN_FILENO);
		return (EXIT_FAILURE);
	}
	unlink(temp_file);
	free(temp_file);
	return (EXIT_SUCCESS);
}

int	redir_in(t_expression *expr, t_redir *redir_data)
{
	char	*delimiter;

	if (is_heredoc(redir_data->file))
	{
		delimiter = get_delimiter(redir_data->file);
		return (handle_heredoc(expr, delimiter));
	}
	if (save_fd(&expr->saved_stdin, STDIN_FILENO) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	if (make_redir(STDIN_FILENO, redir_data->file, O_RDONLY) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_redir	*create_heredoc(char *delimiter)
{
	t_redir	*redir;
	char	*heredoc_file;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	heredoc_file = ft_strjoin("HEREDOC:", delimiter);
	if (!heredoc_file)
	{
		free(redir);
		return (NULL);
	}
	redir->type = REDIR_IN;
	redir->file = heredoc_file;
	return (redir);
}
