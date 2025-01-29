/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/29 14:06:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv)
{
	char	buffer[2048];
	char	*clear_screen;

	(void)argc;
	(void)argv;
	// Load terminal capabilities
	if (tgetent(buffer, getenv("TERM")) != 1)
	{
		fprintf(stderr, "Could not retrieve terminal capabilities.\n");
		return (1);
	}
	// Get the clear screen capability
	clear_screen = tgetstr("cl", NULL);
	if (clear_screen)
	{
		tputs(clear_screen, 1, ft_putchar); // Clear screen
	}
	else
	{
		fprintf(stderr, "Terminal does not support clearing the screen.\n");
	}
	return (0);
}
