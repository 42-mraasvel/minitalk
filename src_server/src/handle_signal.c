#include "server.h"
#include "vecstr.h"
#include <signal.h>

static volatile t_sig_data	g_sig_data;

void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signal == SIGUSR1)
		g_sig_data.bit = 1;
	else
		g_sig_data.bit = 0;
	g_sig_data.next = true;
	g_sig_data.client = info->si_pid;
}

static void	send_acknowledgement(int signal)
{
	kill(g_sig_data.client, signal);
}

/*
When a signal is received, pushback bit into array
Send acknowledgement (SIGUSR1) after each bit
If null terminator character was received, flush and print string

SIGUSR2 is send when the final bit is received
*/

void	listen(t_vecstr *storage)
{
	while (true)
	{
		if (g_sig_data.next)
		{
			g_sig_data.next = false;
			vecstr_push_bit(storage, g_sig_data.bit);
			if (vecstr_end(storage))
			{
				vecstr_flush(storage);
				send_acknowledgement(SIGUSR2);
			}
			send_acknowledgement(SIGUSR1);
		}
	}
}
