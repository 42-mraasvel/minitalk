#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

void	ft_putnum(int n);
void	ft_bzero(void *mem, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);

void	*ft_malloc(size_t size);
void	ft_putstr(int fd, const char *str);

#endif /* UTILS_H */
