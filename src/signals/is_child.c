/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:37:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/15 15:08:02 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	heredoc_handler(int signum)
{
	(void)signum;
	rl_done = 1;
	rl_replace_line("", 0);
	close(STDIN_FILENO);
}

void	ft_sigmode_heredoc(void)
{
	set_sighandler(SIGINT, heredoc_handler);
	set_sighandler(SIGQUIT, SIG_IGN);
}
