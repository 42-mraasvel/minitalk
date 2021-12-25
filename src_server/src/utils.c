#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *mem, size_t size)
{
	unsigned char	*p;

	p = mem;
	while (size > 0)
	{
		*p = 0;
		size--;
		p++;
	}
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dst;
	s = src;
	while (n > 0)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr(STDERR_FILENO, "error: malloc\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
