/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:19:51 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 20:40:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_plist	*ms_lstlocate(t_plist *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (lst && i++ < n)
		lst = lst->next;
	return (lst);
}

t_plist	*ms_lstlast(t_plist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t	ms_lstsize(t_plist *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_plist	*ms_lstnew(char *key, char *value)
{
	t_plist	*lst;

	lst = malloc(sizeof(t_plist));
	if (!lst)
		return (0);
	lst->key = key;
	lst->value = value;
	lst->next = 0;
	return (lst);
}

void	ms_lstadd_front(t_plist **lst, t_plist *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
