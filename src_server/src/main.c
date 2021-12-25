#include "utils.h"
#include "server.h"
#include "vecstr.h"
#include <unistd.h>

static void	putpid(void)
{
	ft_putnum(getpid());
	write(STDOUT_FILENO, "\n", 1);
}

/*
1. Setup mask (can't interrupt signal handler with SIGUSR1 and SIGUSR2)
2. Specify that we should use a handler with extra information (ack)
*/

static void	initialize_signals(void)
{
	struct sigaction	sa;
	sigset_t			set;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	t_vecstr	*storage;

	putpid();
	initialize_signals();
	storage = vecstr_construct();
	listen(storage);
	vecstr_destroy(storage);
	return (0);
}
