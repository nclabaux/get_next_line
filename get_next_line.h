#define BUFFER_SIZE 4

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int 	get_next_line(int fd, char **line);
int		ft_buffer_rd(char buffer[BUFFER_SIZE], char **line, int *index);
void	ft_buffer_cut(char buffer[BUFFER_SIZE]);

#endif
