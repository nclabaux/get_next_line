/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 01:57:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/05 01:57:49 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	long		check;
	int			index;
	int			end_of_file;

	if (!(*line))
		if (!(ft_memory_alloc(line)))
			return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	end_of_file = 0;
	index = 0;
	while (!end_of_file)
	{
		check = ft_buffer_rd(buffer, line, &index);
		if (check)
			return (1);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == 0 || check == -1)
			return (check);
		if (check < BUFFER_SIZE && buffer[0] == 0)
			end_of_file = 1;
	}
	ft_buffer_rd(buffer, line, &index);
	return (0);
}

int		ft_buffer_rd(char *buffer, char **line, int *index)
{
	while (buffer[0])
	{
		if (buffer[0] == '\n')
		{
			*((*line) + (*index)) = '\0';
			ft_buffer_cut(buffer);
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

void	ft_buffer_cut(char *buffer)
{
	long	i;

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
		while (i < BUFFER_SIZE - 1 && buffer[i])
		{
			buffer[i] = buffer[i + 1];
			i++;
		}
		buffer[i] = 0;
	}
}

int		ft_memory_alloc(char **line)
{
	if (!(*line = malloc(sizeof(char) * 1048576)))
		return (0);
	return (1);
}
