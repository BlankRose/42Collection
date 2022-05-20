/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:36:29 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 20:02:25 by flcollar         ###   ########.fr       */
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

static void	ms_tokenize_extension_extra(char *line, t_list **list, int i)
{
	if (ft_isspace(line[i]))
		ft_lstadd_back(list, ft_lstnew(ms_createtoken(0, i, line[i])));
	else if (line[i] == '|')
		ft_lstadd_back(list, ft_lstnew(ms_createtoken(2, i, line[i])));
	else if (line[i] == '<')
		ft_lstadd_back(list, ft_lstnew(ms_createtoken(5, i, line[i])));
	else if (line[i] == '>')
		ft_lstadd_back(list, ft_lstnew(ms_createtoken(6, i, line[i])));
	else
		ft_lstadd_back(list, ft_lstnew(ms_createtoken(1, i, line[i])));
}

static int	ms_tokenize_extension(char *line, t_list **list, int *i)
{
	char	*tmp;
	t_list	*lst;

	if (line[*i] == '\'')
	{
		tmp = ms_parsequotes(&line[++(*i)]);
		lst = ft_lstnew(ms_createtoken(4, *i, '\0'));
		free(((t_tok *)(lst->content))->value);
		((t_tok *)(lst->content))-> value = tmp;
		ft_lstadd_back(list, lst);
		*i += ft_strlen(tmp);
		return (1);
	}
	else if (line[*i] == '\"')
	{
		tmp = ms_parsedbquotes(&line[++(*i)]);
		lst = ft_lstnew(ms_createtoken(4, *i, '\0'));
		free(((t_tok *)(lst->content))->value);
		((t_tok *)(lst->content))->value = tmp;
		ft_lstadd_back(list, lst);
		while (line[*i] != '\"')
			(*i)++;
		return (1);
	}
	return (0);
}

t_list	**ms_tokenize(char *line)
{
	t_list	**list;
	t_list	*tokens;
	int		i;

	i = -1;
	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	tokens = 0;
	*list = tokens;
	while (line[++i])
	{
		if (!ms_tokenize_extension(line, list, &i))
			ms_tokenize_extension_extra(line, list, i);
	}
	return (list);
}
