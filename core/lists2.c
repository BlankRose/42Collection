/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:37:00 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 19:45:53 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_lstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ms_lstlast(*lst);
		last->next = new;
	}
}

int	ms_printlist(t_plist *lst)
{
	if (!lst)
		return (-1);
	while (lst)
	{
		printf("Key : Value %s   : %s \n", lst -> key, lst -> value);
		lst = lst -> next;
	}
	return (1);
}

void	ms_plstdelone(t_plist *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->key);
		del(lst->value);
	}
	free(lst);
}

void	ms_plstclear(t_plist **lst, void (*del)(void*))
{
	t_plist	*current;
	t_plist	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ms_plstdelone(current, del);
		current = next;
	}
	*lst = 0;
}
