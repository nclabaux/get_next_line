/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:24:56 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/19 19:49:29 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

struct	s_char_list
{
	char				c;
	int					num;
	struct s_char_list	*next;
};

typedef struct s_char_list t_char_list;

int		get_next_line(int fd, char **line);
int		ft_buffer_rd(char *buffer, int *index, t_char_list **astock);
void	ft_buffer_cut(char *buffer);
int		ft_init(char **line);
int		ft_write_in_line(t_char_list **astock, int index, char **line);

t_char_list	*ft_lstnew(char c, int num);
t_char_list	*ft_lstlast(t_char_list *lst);
int			ft_lstchar_add_back(t_char_list **alst, char c, int num);

#endif
