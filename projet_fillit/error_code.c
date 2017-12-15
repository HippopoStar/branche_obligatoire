#include <fillit.h>

void	error_code(char *error)
{
	if(error)
	{
		ft_putstr(error);
		exit (-1);
	}
}
