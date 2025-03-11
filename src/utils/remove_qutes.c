/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_qutes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:01:11 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 16:18:26 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	len_without_quotes(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != '\'' && *str != '\"')
			len++;
		str++;
	}
	return (len);
}

int	remove_quotes(char **str)
{
	char	*new;
	int		i;
	int		j;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	new = malloc(len_without_quotes(*str) + 1);
	if (!new)
		return (EXIT_FAILURE);
	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
			i++;
		else
			new[j++] = (*str)[i++];
	}
	new[j] = '\0';
	free(*str);
	*str = new;
	return (EXIT_SUCCESS);
}
