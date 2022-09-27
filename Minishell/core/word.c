/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:59:57 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 19:42:05 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
