#include "utils.h"
#include "client.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	pid_t	server;

	if (!valid_args(argc, argv))
	{
		ft_error(ARG_ERROR);
		return (1);
	}
	server = ft_atoi(argv[1]);
	send_data(argv[2], server);
	sleep(2);
	ft_putstr(STDOUT_FILENO, "client: " LOST_MSG);
	return (0);
}
