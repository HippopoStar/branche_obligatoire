
#include "fillit.h"

char	*initialise_color(void)
{
	char	*color;

	if (!(color = (char *)malloc(6 * sizeof(char))))
		exit (-1);
	*(color + 0) = '\033';
	*(color + 1) = '[';
	*(color + 2) = '0';
	*(color + 3) = '0';
	*(color + 4) = 'm';
	*(color + 5) = '\0';
	return (color);
}

void	write_color(char c, char *color)
{
	if (c == '.')
	{
		write(1, &c, 1);
	}
	else
	{
		*(color + 3) = '1';
		write(1, color, 6);
		*(color + 2) = '3';
		*(color + 3) = '1' + ((c - 'A') % 6);
		write(1, color, 6);
		write(1, &c, 1);
		*(color + 2) = '0';
		*(color + 3) = '0';
		write(1, color, 6);
	}
}

void	print_grid(char **grid)
{
	size_t	i;
	size_t	j;
	char	*color;
	char	c;

	color = initialise_color();
	i = 0;
	while (*(grid + i) != NULL)
	{
		j = 0;
		while ((c = *(*(grid + i) + j)) != '\0')
		{
			write_color(c, color);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
