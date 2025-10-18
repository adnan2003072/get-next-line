#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <bsd/string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef unsigned char	t_uchar;

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
long	find_newline(char *text);
char	*get_next_line(int fd);

#endif // !GET_NEXT_LINE_H
