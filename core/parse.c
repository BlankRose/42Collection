/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:43:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 21:34:24 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static char	*ms_parsedq_expension(char *str, char *tmp, int *i)
{
	char	*env;

	if (!ft_strncmp(&str[*i], "$?", 2))
	{
		tmp = ft_strexpend(tmp, ft_itoa(g_main->last_exit_code), TRUE);
		*i += 2;
	}
	if (str[*i] == '$')
	{
		env = ms_getfromenvp(&str[++(*i)]);
		if (env && env[0])
			tmp = ft_strexpend(tmp, env, TRUE);
		while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
			(*i)++;
	}
	else
		tmp = ft_strexpend(tmp, ft_substr(&str[(*i)++], 0, 1), TRUE);
	return (tmp);
}

char	*ms_parsequotes(char *str)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	i = 0;
	while (str[i] && str[i] != '\'')
	{
		tmp = ms_charjoin(tmp, str[i]);
		i++;
	}
	return (tmp);
}

char	*ms_parsedbquotes(char *str)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp = 0;
	i = 0;
	while (str[i] && str[i] != '\"')
		tmp = ms_parsedq_expension(str, tmp, &i);
	if (!str[i])
	{
		perror("Errors in opening double quotes");
		exit(1);
	}
	return (tmp);
}

void	ms_parse_words(t_list **tokens)
{
	t_list	*current;
	t_list	*prev;
	t_tok	*token;

	current = *tokens;
	prev = 0;
	while (current)
	{
		token = (t_tok *) current->content;
		if (token->type == WORD)
			token->value = ms_parsedunquotes(token->value);
		if (!token->value)
		{
			if (!prev)
				*tokens = current->next;
			else
				prev->next = current->next;
			ft_lstdelone(current, free);
			current = *tokens;
			continue ;
		}
		prev = current;
		current = current->next;
	}
}

char	*ms_parsedunquotes(char *str)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp = 0;
	i = 0;
	while (str[i])
		tmp = ms_parsedq_expension(str, tmp, &i);
	if (str)
		free(str);
	return (tmp);
}
