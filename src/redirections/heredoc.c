/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:15:05 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/10 16:21:11 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	setup_vars(char **result, char **prompt, const char *eof_str)
{
	*result = ft_strdup("");
	if (!*result)
		return (EXIT_FAILURE);
	*prompt = ft_strjoin(eof_str, PROMPT_HEREDOC);
	if (!*prompt)
		return (free(*result), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*get_str(const char *eof_str)
{
	char	*result;
	char	*new_line;
	char	*prompt;

	if (setup_vars(&result, &prompt, eof_str) == EXIT_FAILURE)
		return (NULL);
	new_line = readline(prompt);
	if (!new_line)
		return (free(result), free(prompt), NULL);
	while (ft_strcmp(new_line, eof_str))
	{
		if (ft_strjoin_inplace(&result, new_line) == EXIT_FAILURE)
			return (free(result), free(prompt), free(new_line), NULL);
		if (ft_strjoin_inplace(&result, "\n") == EXIT_FAILURE)
			return (free(result), free(prompt), free(new_line), NULL);
		free(new_line);
		new_line = readline(prompt);
		if (!new_line)
			return (free(result), free(prompt), NULL);
	}
	return (free(new_line), free(prompt), result);
}

static int	create_file(const char *file_path, const char *str)
{
	int		fd;
	ssize_t	bytes_written;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC,
			DEFAULT_FILE_PERMISSIONS);
	if (fd == -1)
		return (EXIT_FAILURE);
	bytes_written = write(fd, str, strlen(str));
	close(fd);
	if (bytes_written == -1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	redir_heredoc(t_minishell *ms, t_expression *expr, t_redir *redir_data)
{
	char	*str;
	char	*numb_str;

	numb_str = ft_itoa(ms->heredoc_count);
	ms->heredoc_count++;
	if (!numb_str)
		return (EXIT_FAILURE);
	str = get_str(redir_data->file);
	if (!str)
		return (free(numb_str), EXIT_FAILURE);
	free(redir_data->file);
	redir_data->file = ft_strjoin(TMP_FILE_PATH_HEREDOC, numb_str);
	if (!redir_data->file)
		return (free(str), free(numb_str), EXIT_FAILURE);
	if (create_file(redir_data->file, str) == EXIT_FAILURE)
		return (free(str), free(numb_str), EXIT_FAILURE);
	free(str);
	free(numb_str);
	if (save_fd(&expr->saved_stdin, STDIN_FILENO) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	if (make_redir(STDIN_FILENO, redir_data->file, O_RDONLY) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
