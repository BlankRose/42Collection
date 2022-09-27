/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:55:54 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/23 15:30:47 by flcollar         ###   ########.fr       */
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

t_list	*ft_lstlocate(t_list *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (lst && i++ < n)
		lst = lst->next;
	return (lst);
}

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!lst || !f || !del)
		return (0);
	return (res);
}*/
