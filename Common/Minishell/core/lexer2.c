/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:49:10 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 20:38:48 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_tokjoining(t_list *list)
{
	t_tok	*currtok;
	t_tok	*nexttok;

	while (list && list -> next)
	{
		currtok = (t_tok *)(list -> content);
		nexttok = (t_tok *)(list -> next -> content);
		if (currtok -> type == WORD && currtok -> type == nexttok -> type)
			ms_wordtokjoining(list);
		else if (currtok -> type == SEP && currtok -> type == nexttok -> type)
			ms_spacetokjoining(list);
		else if (currtok -> type == REDIR_IN
			&& currtok -> type == nexttok -> type)
			ms_redirtokjoining(list, REDIR_IN);
		else if (currtok -> type == REDIR_OUT
			&& currtok -> type == nexttok -> type)
			ms_redirtokjoining(list, REDIR_OUT);
		else
			list = list -> next;
	}
}

void	ms_createheredoc(char *end)
{
	int		fd;
	char	*line;

	fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, end, ft_min(ft_strlen(line) - 1, ft_strlen(end))))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	close(fd);
}

static void	ms_spacetokdel_extension(t_list **lst, t_list *tmplst)
{
	t_tok	*currtok;
	t_tok	*nexttok;

	currtok = (t_tok *)((*lst)->content);
	nexttok = (t_tok *)((*lst)->next->content);
	if (nexttok -> type == SEP)
	{
		tmplst = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		free(nexttok -> value);
		free(nexttok);
		free(tmplst);
	}
	(*lst) = (*lst)->next;
}

void	ms_spacetokdel(t_list **list)
{
	t_list	*tmplst;
	t_list	*lst;

	if (!list)
		return ;
	lst = *list;
	tmplst = 0;
	if (lst && ((t_tok *)(lst->content))->type == SEP)
	{	
		*list = lst -> next;
		free(((t_tok *)(lst->content))->value);
		free(lst -> content);
		free(lst);
	}
	while (lst && lst -> next)
		ms_spacetokdel_extension(&lst, tmplst);
}

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
