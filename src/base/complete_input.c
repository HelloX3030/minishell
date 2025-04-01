/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:05 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/01 15:16:55 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	balance_quotes(char *input)
{
	int	single_q;
	int	double_q;
	int	i;

	single_q = 0;
	double_q = 0;
	i = 0;
	while	(input[i])
	{
		if (input[i] == '\'' && !double_q)
			single_q = !single_q;
		else if (input[i] == '\"' && !single_q)
			double_q = !double_q;
		i ++;
	}
	return (!single_q && !double_q);
}

char	*balance_input(void)
{
	char	*input;
	char	*cont;
	char	*temp;

	input = readline(PROMPT);
	if (!input)
		return (NULL);
	while (!balance_quotes(input))
	{
		cont = readline("quote> ");
		if (!cont)
		{
			free(input);
			return (NULL);
		}
		temp = ft_strjoin(input, "\n");
		free(input);
		input = ft_strjoin(temp, cont);
		free(temp);
		free(cont);
	}
	return (input);
}
