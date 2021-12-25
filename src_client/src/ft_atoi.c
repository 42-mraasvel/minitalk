#include "utils.h"
#include <stdio.h>

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;

	sign = 1;
	i = skip_spaces(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = 0;
	while (str[i])
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
