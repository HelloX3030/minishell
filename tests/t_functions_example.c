/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_functions_example.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/29 14:15:53 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(void)
{
	char	buffer[2048];
	char	*pos_cmd;

	char *clear_screen, *move_cursor, *bold_text, *reset_text;
	// Load terminal capabilities
	if (tgetent(buffer, getenv("TERM")) != 1)
	{
		fprintf(stderr, "Could not retrieve terminal capabilities.\n");
		return (1);
	}
	// Get the clear screen capability
	clear_screen = tgetstr("cl", NULL);
	if (clear_screen)
		tputs(clear_screen, 1, ft_putchar);
	// Get cursor movement capability
	move_cursor = tgetstr("cm", NULL);
	if (move_cursor)
	{
		pos_cmd = tgoto(move_cursor, 10, 5);
		tputs(pos_cmd, 1, ft_putchar);
	}
	// Get bold text capability
	bold_text = tgetstr("md", NULL);
	reset_text = tgetstr("me", NULL);
	if (bold_text)
		tputs(bold_text, 1, ft_putchar); // Start bold
	printf("Hello, World!\n");
	if (reset_text)
		tputs(reset_text, 1, ft_putchar); // Reset attributes
	while (1)
	{
		pause();
	}
	return (0);
}
