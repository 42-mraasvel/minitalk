#ifndef CLIENT_H
# define CLIENT_H

# ifdef __linux__
#  define _GNU_SOURCE
# endif

# define BYTESIZE 8
# define ARG_ERROR "invalid argument"
# define PID_ERROR "invalid pid"

# define CONFIRM_MSG "acknowledgement received\n"
# define LOST_MSG "failed to receive acknowledgement\n"

# include <sys/types.h>

int		valid_args(int argc, char *argv[]);
void	send_data(const char *str, pid_t server);

#endif /* CLIENT_H */
