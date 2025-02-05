/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/05 13:00:51 by lkubler          ###   ########.fr       */
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

#endif
