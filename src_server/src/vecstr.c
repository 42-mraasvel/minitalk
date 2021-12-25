#include "utils.h"
#include "vecstr.h"
#include <stdlib.h>

t_vecstr	*vecstr_construct(void)
{
	t_vecstr	*new;

	new = ft_malloc(1 * sizeof(t_vecstr));
	new->len = 0;
	new->size = INITIAL_SIZE;
	new->table = ft_malloc(INITIAL_SIZE * sizeof(char));
	new->n_bit = BYTE_SIZE;
	return (new);
}

void	vecstr_reset(t_vecstr *vec)
{
	if (!vec)
		return ;
	free(vec->table);
	vec->n_bit = BYTE_SIZE;
	vec->len = 0;
	vec->size = INITIAL_SIZE;
	vec->table = ft_malloc(INITIAL_SIZE * sizeof(char));
}

void	vecstr_destroy(t_vecstr *vec)
{
	if (!vec)
		return ;
	free(vec->table);
	free(vec);
}

static void	vecstr_ensure_cap(t_vecstr *vec)
{
	char	*temp;

	if (vec->len == vec->size - 1)
	{
		vec->size *= 2;
		temp = ft_malloc(vec->size * sizeof(char));
		ft_memcpy(temp, vec->table, vec->len);
		free(vec->table);
		vec->table = temp;
	}
}

void	vecstr_push_back(t_vecstr *vec, char c)
{
	vecstr_ensure_cap(vec);
	vec->table[vec->len] = c;
	vec->len++;
}
