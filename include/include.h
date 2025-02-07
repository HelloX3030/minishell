/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/07 12:10:12 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <limits.h>
# include <unistd.h>
# include <dirent.h>

# define PROMPT "myshell> "

/*
	infile:		"<"
	outfile:	">"
	append:		">>"
	pipe:		"|"
	background:	"&"
	next: (for piping)
*/
typedef struct s_command
{
	char				*cmd;
	char				**args;
	char				*infile;
	char				*outfile;
	bool				append;
	bool				pipe;
	bool				background;
	struct s_command	*next;
}						t_command;

typedef struct	s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

// builtins
static int	to_path(int fl, t_command *args);
static int	path_history(t_command *args);
int			mini_cd(t_command *command);
static int	count_args(char **args);
int			mini_echo(char **args);
void		mini_pwd(void);

// exec
int		is_builtin(char *cmd);
int		dispatch_builtin(t_command *command);
void	execute(t_command *command);

#endif
