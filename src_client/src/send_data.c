#include "client.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

static bool	g_next = false;

static void	send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_error(PID_ERROR);
		exit(EXIT_FAILURE);
	}
}

static void	send_byte(char c, pid_t server)
{
	int	i;
	int	bit;

	i = 0;
	while (i < BYTESIZE)
	{
		g_next = false;
		bit = (c >> i) & 1;
		if (bit)
			send_signal(server, SIGUSR1);
		else
			send_signal(server, SIGUSR2);
		while (!g_next)
			;
		i++;
	}
}

static void	receive_ack(int signal)
{
	(void)signal;
	g_next = true;
}

static void	receive_end(int signal)
{
	(void)signal;
	ft_putstr(STDOUT_FILENO, "client: " CONFIRM_MSG);
	exit(0);
}

void	send_data(const char *str, pid_t server)
{
	int	i;

	i = 0;
	signal(SIGUSR1, receive_ack);
	signal(SIGUSR2, receive_end);
	while (str[i])
	{
		send_byte(str[i], server);
		i++;
	}
	send_byte('\0', server);
}
