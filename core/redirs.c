/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:56:14 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 19:42:13 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_redirtokjoining(t_list *list, int rtype)
{
	t_tok	*currtok;
	t_tok	*nexttok;
	t_list	*tmplst;
	char	*str;
	char	*tmp;

	currtok = (t_tok *)(list -> content);
	nexttok = (t_tok *)(list -> next -> content);
	tmp = currtok -> value;
	str = ft_strjoin(currtok -> value, nexttok -> value);
	free(tmp);
	currtok -> value = str;
	currtok -> type = HEREDOC;
	if (rtype == 6)
		currtok -> type = REDIR_OUT_APP;
	tmplst = list -> next;
	list -> next = list -> next -> next;
	free(nexttok -> value);
	free(nexttok);
	free(tmplst);
}

int	ms_redircheck(t_list *list)
{
	int		redirs[4];	
	int		i;
	t_tok	*currtok;
	t_tok	*nexttok;

	i = -1;
	while (++i < 4)
		redirs[i] = 0;
	while (list && list -> next)
	{
		currtok = (t_tok *)list -> content;
		nexttok = (t_tok *)list -> next ->content;
		if ((currtok -> type == REDIR_IN || currtok -> type == REDIR_OUT \
			|| currtok -> type == HEREDOC || currtok -> type == REDIR_OUT_APP)
			&& (nexttok -> type != WORD && nexttok -> type != QUOTE \
			&& nexttok -> type != DQUOTE))
			return (-1);
		if (currtok -> type == REDIR_IN)
			redirs[0]++;
		if (currtok -> type == REDIR_OUT)
			redirs[1]++;
		if (currtok -> type == HEREDOC)
			redirs[2]++;
		if (currtok -> type == REDIR_OUT_APP)
			redirs[3]++;
		list = list -> next;
	}
	currtok = (t_tok *)list -> content;
	if (currtok -> type == REDIR_IN || currtok -> type == REDIR_OUT
		|| currtok -> type == HEREDOC || currtok -> type == REDIR_OUT_APP)
		return (-1);
	if (redirs[0] + redirs[2] > 1 || redirs[1] + redirs[3] > 1)
		return (-1);
	return (0);
}

static void	ms_setdirs(t_tok *currtok, t_tok *nexttok)
{
	if ((currtok -> type == REDIR_IN || currtok -> type == HEREDOC)
		&& g_main -> fds[0] == 0)
	{
		if (currtok -> type == REDIR_IN)
			g_main -> fds[0] = open(nexttok -> value, O_RDONLY);
		else
		{
			ms_createheredoc(nexttok -> value);
			g_main -> fds[0] = open(HEREDOC_FILE, O_RDONLY);
		}
	}
	if ((currtok -> type == REDIR_OUT || currtok -> type == REDIR_OUT_APP)
		&& g_main -> fds[1] == 1)
	{
		if (currtok -> type == REDIR_OUT)
			g_main -> fds[1] = open(nexttok -> value, \
				O_RDWR | O_CREAT | O_TRUNC, 0777);
		else
			g_main -> fds[1] = open(nexttok -> value, \
				O_RDWR | O_CREAT | O_APPEND, 0777);
	}
}

static void	ms_redirset_extension(t_list **list,
	t_list **previous, t_list **lst)
{
	if (*list == *lst)
	{
		*list = (*lst)->next->next;
		ft_lstdelone((*lst)->next, free);
		ft_lstdelone(*lst, free);
		*lst = *list;
	}
	else
	{
		(*previous)->next = (*lst)->next->next;
		ft_lstdelone((*lst)->next, free);
		ft_lstdelone(*lst, free);
		*lst = *previous;
	}
}

void	ms_redirset(t_list **list)
{
	t_list	*previous;
	t_list	*lst;
	t_tok	*currtok;
	t_tok	*nexttok;

	if (!list)
		return ;
	lst = *list;
	previous = 0;
	while (lst && lst -> next)
	{
		currtok = (t_tok *)(lst -> content);
		nexttok = (t_tok *)(lst->next->content);
		if (currtok -> type == REDIR_IN || currtok -> type == REDIR_OUT
			|| currtok -> type == REDIR_OUT_APP || currtok -> type == HEREDOC)
		{
			ms_setdirs(currtok, nexttok);
			ms_redirset_extension(list, &previous, &lst);
		}
		previous = lst;
		lst = lst -> next;
	}
}
