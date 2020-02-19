/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/18 03:10:24 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_char_list	*ft_lstnew(char c, int num)
{
	t_char_list	*newlink;

	if (!(newlink = malloc(sizeof(t_char_list))))
		return (NULL);
	newlink->c = c;
	newlink->num = num;
	newlink->next = NULL;
	return (newlink);
}

t_char_list	*ft_lstlast(t_char_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstchar_add_back(t_char_list **alst, char c, int num)
{
	t_char_list	*last;
	t_char_list	*new;

	new = ft_lstnew(c, num);
	if (!new || !alst)
		return (0);
	if (!(*alst))
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
	return (1);
}
