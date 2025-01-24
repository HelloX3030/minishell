/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/17 13:26:25 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

// Handle Functions
char	*get_next_line(int fd);
char	*handle_found_nl(char *buffer, char *next_nl, char *nl);
bool	handle_start_buffer(char *buffer, char **nl, size_t *nl_r_len);
bool	read_buffer(int fd, char *buffer, char **nl, size_t *nl_r_len);
char	*get_buffer(int fd);

// Utility Functions
char	*get_next_nl(char *s);
char	*rstr(const char *s, size_t *nl_r_len);
bool	buffer_join(char **nl, char const *buffer, size_t *nl_r_len);
void	failure_cleanup(char *nl);

#endif
