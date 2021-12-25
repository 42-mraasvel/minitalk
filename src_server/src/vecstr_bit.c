#include "utils.h"
#include "vecstr.h"
#include <unistd.h>

void	vecstr_push_bit(t_vecstr *vec, int bit)
{
	if (vec->n_bit == BYTE_SIZE)
	{
		vecstr_push_back(vec, '\0');
		vec->n_bit = 0;
	}
	vec->table[vec->len - 1] += bit << vec->n_bit;
	vec->n_bit++;
}

char	vecstr_back(t_vecstr *vec)
{
	if (vec->n_bit == BYTE_SIZE && vec->len > 0)
		return (vec->table[vec->len - 1]);
	else if (vec->len > 1)
		return (vec->table[vec->len - 2]);
	else
		return (-1);
}

bool	vecstr_end(t_vecstr *vec)
{
	return (vec->n_bit == BYTE_SIZE
		&& vec->len > 0
		&& vecstr_back(vec) == '\0');
}

void	vecstr_flush(t_vecstr *vec)
{
	write(STDOUT_FILENO, vec->table, vec->len - 1);
	vecstr_reset(vec);
}
