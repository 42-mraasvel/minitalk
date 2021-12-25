#ifndef SERVER_H
# define SERVER_H

# ifdef __linux__
#  define _GNU_SOURCE
# endif

# include <stdbool.h>
# include "vecstr.h"
# include <signal.h>

typedef struct s_sig_data
{
	pid_t	client;
	int		bit;
	bool	next;
}	t_sig_data;

void		handle_signal(int signal, siginfo_t *info, void *ucontext);
void		listen(t_vecstr *storage);

#endif /* SERVER_H */
