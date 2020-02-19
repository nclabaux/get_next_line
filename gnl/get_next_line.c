/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:25:17 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/19 20:53:25 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	long		check;
	int			index;
	int			end_of_file;
	t_char_list	*stock;

	if (BUFFER_SIZE < 1)
		return (-1);
	end_of_file = 0;
	index = 0;
	stock = NULL;
	while (!end_of_file)
	{
		check = ft_buffer_rd(buffer, &index, &stock);
		if (check == -1)
			return (-1);
		if (check)
		{
			ft_write_in_line(&stock, index, line);
			return (1);
		}
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == 0 || check == -1)
		{
			if (check == 0)
				ft_write_in_line(&stock, index, line);
			return (check);
		}
		if (check < BUFFER_SIZE && buffer[0] == 0)
			end_of_file = 1;
	}
	check = ft_buffer_rd(buffer, &index, &stock);
	if (check == -1)
		return (-1);
	ft_write_in_line(&stock, index, line);
	return (0);
}

int		ft_buffer_rd(char *buffer, int *index, t_char_list **astock)
{
	while (buffer[0])
	{
		if (buffer[0] == '\n')
		{
			ft_lstchar_add_back(astock, '\0', *index);
			ft_buffer_cut(buffer);
			return (*index + 1);
		}
		else
		{
			ft_lstchar_add_back(astock, buffer[0], *index);
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

int		ft_write_in_line(t_char_list **astock, int index, char **line)
{
	t_char_list	*buff;
	int			last;

	if (!(*line = malloc(sizeof(char) * index + 1)))
		return (0);
	while (*astock)
	{
		last = (*astock)->num;
		*((*line) + last )= (*astock)->c;
		buff = (*astock)->next;
		free(*astock);
		*astock = buff;
	}
	*((*line) + last + 1) = '\0';
	return (1);
}
