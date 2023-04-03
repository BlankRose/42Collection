/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:55:54 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 11:46:06 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstiter_arg(t_list *lst, void (*f)(void *, void *), void *param)
{
	while (lst && f)
	{
		f(lst->content, param);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}

t_list	*ft_lstmap_arg(t_list *lst, void *(*f)(void *, void *),
	void (*del)(void *), void *param)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content, param));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}

void	ft_lstupdate(t_list *lst, void (*del)(void *), void *new)
{
	if (!lst)
		return ;
	if (del && lst->content)
		del(lst->content);
	lst->content = new;
}
