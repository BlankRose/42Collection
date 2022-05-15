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

void	ms_lstadd_back(t_plist **lst, t_plist *new)
{
	t_plist *last;

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

int ms_printlist(t_plist *lst)
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
