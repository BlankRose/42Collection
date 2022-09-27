/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:59 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 16:01:20 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

t_list	*ft_lstdup(t_list *lst, void *(*f) (void *))
{
	if (!f || !lst)
		return (0);
	return (ft_lstnew(f(lst->content)));
}

void	ft_lstadd_front(t_list **lst, t_list *new)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

t_list	*ft_array2lst(void **array, size_t n)
{
	t_list	*lst;
	size_t	i;

	if (!array)
		return (0);
	lst = ft_lstnew(*(array++));
	i = 0;
	while ((!n && array) || (n && i < n))
		ft_lstadd_back(&lst, ft_lstnew(*(array++)));
	return (lst);
}
