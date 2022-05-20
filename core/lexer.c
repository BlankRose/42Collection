/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:36:29 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 17:03:29 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_tok	*ms_createtoken(int type, int index, char value)
{
	t_tok	*tok;

	tok = malloc(sizeof(*tok));
	if (!tok)
		return (NULL);
	tok->value = malloc(sizeof(char) * 2);
	tok->index = index;
	tok->type = type;
	tok->value[0] = value;
	tok->value[1] = '\0';
	return (tok);
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
			return ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
}

t_list	**ms_tokenize(char *line)
{
	t_list	**list;
	t_list	*tokens;
	char	*tmp;
	t_list	*lst;
	int		i;

	i = -1;
	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	tokens = 0;
	*list = tokens;
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			ft_lstadd_back(list, ft_lstnew(ms_createtoken(0, i, line[i])));
		else if (line[i] == '|')
			ft_lstadd_back(list, ft_lstnew(ms_createtoken(2, i, line[i])));
		else if (line[i] == '\'')
		{
			tmp = ms_parsequotes(&line[++i]);
			lst = ft_lstnew(ms_createtoken(4, i, '\0'));
			free(((t_tok *)(lst->content))->value);
			((t_tok *)(lst->content))-> value = tmp;
			ft_lstadd_back(list, lst);
			i += ft_strlen(tmp);
		}
		else if (line[i] == '\"')
		{
			tmp = ms_parsedbquotes(&line[++i]);
			lst = ft_lstnew(ms_createtoken(4, i, '\0'));
			free(((t_tok *)(lst->content))->value);
			((t_tok *)(lst->content))->value = tmp;
			ft_lstadd_back(list, lst);
			while (line[i] != '\"')
				i++;
		}
		else if (line[i] == '<')
			ft_lstadd_back(list, ft_lstnew(ms_createtoken(5, i, line[i])));
		else if (line[i] == '>')
			ft_lstadd_back(list, ft_lstnew(ms_createtoken(6, i, line[i])));
		else
			ft_lstadd_back(list, ft_lstnew(ms_createtoken(1, i, line[i])));
	}
	return (list);
}

void	ms_spacetokjoining(t_list *list)
{
	t_tok	*nexttok;
	t_list	*tmplst;

	nexttok = (t_tok *)(list -> next -> content);
	tmplst = list -> next;
	list -> next = list -> next -> next;
	free(nexttok -> value);
	free(nexttok);
	free(tmplst);
}

void	ms_wordtokjoining(t_list *list)
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
	tmplst = list -> next;
	list -> next = list -> next -> next;
	free(nexttok -> value);
	free(nexttok);
	free(tmplst);
}

void	ms_wqjoining(t_list *list)
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
	tmplst = list -> next;
	list -> next = list -> next -> next;
	free(nexttok -> value);
	free(nexttok);
	free(tmplst);
}

void	ms_wordquotesjoining(t_list *list)
{
	t_tok	*currtok;
	t_tok	*nexttok;
	int		joined;

	while (list && list -> next)
	{
		joined = 0;
		currtok = (t_tok *)(list -> content);
		nexttok = (t_tok *)(list -> next -> content);
		if ((currtok -> type == WORD || currtok -> type == QUOTE
				|| currtok -> type == DQUOTE) && (nexttok -> type == WORD
				|| nexttok -> type == QUOTE || nexttok -> type == DQUOTE))
		{
			ms_wqjoining(list);
			joined = 1;
		}
		if (!joined)
			list = list -> next;
	}
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

void	ms_spacetokdel(t_list **list)
{
	t_list	*tmplst;
	t_list	*lst;
	t_tok	*currtok;
	t_tok	*nexttok;

	if (!list)
		return ;
	lst = *list;
	if (lst && ((t_tok *)(lst->content))->type == SEP)
	{	
		*list = lst -> next;
		free(((t_tok *)(lst->content))->value);
		free(lst -> content);
		free(lst);
	}
	while (lst && lst -> next)
	{
		currtok = (t_tok *)(lst -> content);
		nexttok = (t_tok *)(lst -> next -> content);
		if (nexttok -> type == SEP)
		{
			tmplst = lst -> next;
			lst -> next = lst -> next -> next;
			free(nexttok -> value);
			free(nexttok);
			free(tmplst);
		}
		lst = lst -> next;
	}	
}

int	ms_pipecheck(t_list *list)
{
	t_tok	*currtok;
	t_tok	*nexttok;

	if (((t_tok *) list->content)->type == PIPE)
		return (-1);
	while (list && list -> next)
	{
		currtok = (t_tok *)list -> content;
		nexttok = (t_tok *)list -> next ->content;
		if (currtok -> type == PIPE
			&& nexttok -> type == PIPE)
			return (-1);
		list = list -> next;
	}
	currtok = (t_tok *)list -> content;
	if (currtok -> type == PIPE)
		return (-1);
	return (0);
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
	if (currtok -> type == REDIR_IN || currtok -> type == REDIR_OUT ||
		currtok -> type == HEREDOC || currtok -> type == REDIR_OUT_APP)
		return (-1);
	if (redirs[0] + redirs[2] > 1 || redirs[1] + redirs[3] > 1)
		return (-1);	
	return (0);
}

void	ms_tokjoining(t_list *list)
{
	t_tok	*currtok;
	t_tok	*nexttok;
	int		joined;

	while (list && list -> next)
	{
		joined = 0;
		currtok = (t_tok *)(list -> content);
		nexttok = (t_tok *)(list -> next -> content);
		if (currtok -> type == WORD && currtok -> type == nexttok -> type)
		{
			ms_wordtokjoining(list);
			joined = 1;
		}
		if (currtok -> type == SEP && currtok -> type == nexttok -> type)
		{
			ms_spacetokjoining(list);
			joined = 1;
		}
		if (currtok -> type == REDIR_IN && currtok -> type == nexttok -> type)
		{
			ms_redirtokjoining(list, REDIR_IN);
			joined = 1;
		}
		if (currtok -> type == REDIR_OUT && currtok -> type == nexttok -> type)
		{
			ms_redirtokjoining(list, REDIR_OUT);
			joined = 1;
		}
		if (!joined)
			list = list -> next;
	}
}
