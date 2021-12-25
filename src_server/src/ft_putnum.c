#include <unistd.h>

static void	ft_putdigits(unsigned int n)
{
	char	c;

	if (n == 0)
		return ;
	ft_putdigits(n / 10);
	c = (char)(n % 10 + '0');
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnum(int n)
{
	if (n == 0)
		write(STDOUT_FILENO, "0", 1);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putdigits(-n);
	}
	else
		ft_putdigits(n);
}
