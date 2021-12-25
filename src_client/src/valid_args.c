#include <stdbool.h>
#include "utils.h"

int	valid_args(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		return (false);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (false);
		i++;
	}
	return (true);
}
