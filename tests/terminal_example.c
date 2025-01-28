#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>

struct termios	orig_termios;

void	enable_raw_mode(void)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
	raw = orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON | ISIG);
	raw.c_iflag &= ~(IXON | ICRNL);
	raw.c_oflag &= ~OPOST;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	disable_raw_mode(void)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios) == -1)
	{
		perror("tcsetattr");
	}
}

void	move_cursor(int row, int col)
{
	char	buffer[1024];
	char	*area;
	char	*cm;

	area = buffer;
	if (tgetent(buffer, getenv("TERM")) <= 0)
	{
		fprintf(stderr, "Could not get terminal capabilities\n");
		exit(1);
	}
	cm = tgetstr("cm", &area);
	if (cm)
	{
		tputs(tgoto(cm, col, row), 1, putchar);
	}
}

void	clear_mini_terminal(void)
{
	char	buffer[1024];
	char	*area;
	char	*cl;

	area = buffer;
	if (tgetent(buffer, getenv("TERM")) <= 0)
	{
		fprintf(stderr, "Could not get terminal capabilities\n");
		exit(1);
	}
	cl = tgetstr("cl", &area);
	if (cl)
	{
		tputs(cl, 1, putchar);
	}
}

void	handle_input(void)
{
	char	c;
	int		row;
	int		col;
	char	seq[2];

	row = 5;
	col = 5;
	clear_mini_terminal();
	move_cursor(row, col);
	printf("Press 'q' to quit.\n");
	fflush(stdout);
	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		if (c == 'q')
			break ;
		if (c == '\033')
		{
			if (read(STDIN_FILENO, &seq[0], 1) == 0)
				break ;
			if (read(STDIN_FILENO, &seq[1], 1) == 0)
				break ;
			if (seq[0] == '[')
			{
				switch (seq[1])
				{
				case 'A':
					row = (row > 0) ? row - 1 : row;
					break ;
				case 'B':
					row = (row < 20) ? row + 1 : row;
					break ;
				case 'C':
					col = (col < 50) ? col + 1 : col;
					break ;
				case 'D':
					col = (col > 0) ? col - 1 : col;
					break ;
				}
			}
		}
		else
		{
			move_cursor(row, col);
			printf("%c", c);
			fflush(stdout);
			col++;
		}
		move_cursor(row, col);
		fflush(stdout);
	}
}

int	main(void)
{
	enable_raw_mode();
	atexit(disable_raw_mode);
	handle_input();
	return (0);
}
