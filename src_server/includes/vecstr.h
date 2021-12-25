#ifndef VECSTR_H
# define VECSTR_H

# include <stddef.h>
# include <stdbool.h>
# define INITIAL_SIZE 512
# define BYTE_SIZE 8

typedef struct s_vecstr
{
	char	*table;
	size_t	size;
	size_t	len;
	int		n_bit;
}	t_vecstr;

t_vecstr	*vecstr_construct(void);
void		vecstr_reset(t_vecstr *vec);
void		vecstr_destroy(t_vecstr *vec);
void		vecstr_push_back(t_vecstr *vec, char c);

void		vecstr_push_bit(t_vecstr *vec, int bit);
bool		vecstr_end(t_vecstr *vec);
void		vecstr_flush(t_vecstr *vec);
char		vecstr_back(t_vecstr *vec);

#endif /* VECSTR_H */
