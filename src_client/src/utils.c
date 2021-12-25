#include <unistd.h>
#include <stddef.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
\f \n \r \t \v ' '
*/
int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_error(const char *str)
{
	ft_putstr(STDERR_FILENO, "error: ");
	ft_putstr(STDERR_FILENO, str);
	write(STDERR_FILENO, "\n", 1);
}
