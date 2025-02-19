/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 10:38:20 by lkubler          ###   ########.fr       */
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
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

// builtins
int	to_path(int fl, t_env *env);
int			mini_cd(t_command *command, t_env *env);
int	count_args(char **args);
int			mini_echo(char **args);
void		mini_env(t_env *env);
int			mini_export(char **args, t_env **env);
void		mini_pwd(void);
int			is_valid_id(const char *str);
int			mini_unset(char **args, t_env **env);

// envs
t_env	*create_env_node(char *key, char *value);
void	add_env_node(t_env **head, t_env *new_node);
t_env	*init_env(char **envp);
char	*get_env_value(t_env *env, const char *key);
void	set_env_val(t_env **env, char *key, char *value);
void	unset_env_val(t_env **env, const char *key);
char	**env_to_array(t_env *env);

// exec
int		is_builtin(char *cmd);
int	dispatch_builtin(t_command *command, t_env **env);
void	execute(t_command *command, t_env *env);

// externals
char	*find_cmd_path(const char *cmd, t_env *env);
void	free_array(char **array);
int		execute_ext(t_command *cmd, t_env *env);

#endif
