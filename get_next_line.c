

#include "get_next_line.h"

int 	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	int			status;
	int			check;
	int			i;
	int			index;

	if (BUFFER_SIZE < 1)
		return (-1);
	i = 1;
	index = 0;
	while (i)
	{
		status = ft_buffer_rd(buffer, line, &index);
		if (status)
			return (1);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == 0 || check == -1)
			return (check);
	}
	return (-1);
}

int		ft_buffer_rd(char buffer[BUFFER_SIZE], char **line, int *index)
{
	while (buffer[0])
	{
		if (buffer[0] == '\n')
		{
			*((*line) + (*index)) = '\0';
			ft_buffer_cut(buffer);
			if (*index == BUFFER_SIZE - 1)
				return (0);
			return (*index + 1);
		}
		else
		{
			*((*line) + (*index)) = buffer[0];
			ft_buffer_cut(buffer);
			(*index)++;
		}
	}
	return (0);
}

void	ft_buffer_cut(char buffer[BUFFER_SIZE])
{
	int i;

	if (BUFFER_SIZE == 1)
		buffer[0] = 0;
	else if (BUFFER_SIZE == 2)
	{
		buffer[0] = buffer[1];
		buffer[1] = 0;
	}
	else
	{
		i = 0;
		while (i < BUFFER_SIZE - 1)
		{
			buffer[i] = buffer[i + 1];
			i++;
		}
		buffer[BUFFER_SIZE - 1] = 0;
	}
}
