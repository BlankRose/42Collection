/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:43:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 14:46:44 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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

//NOT FINISHED
char	*ms_parsedbquotes(char *str)
{
	int		i;
	char	*tmp;
	char	*env;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp = 0;
	i = 0;
	while (str[i] && str[i] != '\"')
	{
		if (!ft_strncmp(&str[i], "$?", 2))
		{
			tmp = ft_strexpend(tmp, ft_itoa(g_main->last_exit_code), TRUE);
			i += 2;
		}
		if (str[i] == '$')
		{
			env = ms_getfromenvp(&str[++i]);
			if (env && env[0])
				tmp = ft_strexpend(tmp, env, TRUE);
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
		}
		else
			tmp = ft_strexpend(tmp, ft_substr(&str[i++], 0, 1), TRUE);
	}
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
	char	*env;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], "$?", 2))
		{
			tmp = ft_strexpend(tmp, ft_itoa(g_main->last_exit_code), TRUE);
			i += 2;
		}
		if (str[i] == '$')
		{
			env = ms_getfromenvp(&str[++i]);
			if (env && env[0])
				tmp = ft_strexpend(tmp, env, TRUE);
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
		}
		else
			tmp = ft_strexpend(tmp, ft_substr(&str[i++], 0, 1), TRUE);
	}
	if (str)
		free(str);
	return (tmp);
}

// char	*ms_parseline(char *line)
// {
// 	char	*commands;
// 	char	*tmp;
// 	int		i;

// 	commands = malloc(sizeof(*commands));
// 	if (!commands)
// 		return (NULL);
// 	commands[0] = '\0';
// 	i = 0;
// 	while (line[i] && ft_isspace(line[i]))
// 		i++;
// 	while (line[i])
// 	{
// 		if (line[i] == '\"')
// 		{
// 			tmp = ms_parsedbquotes(&line[++i]);
// 			commands = ft_strjoin(commands, tmp);
// 			while (line[i] && line[i] != '\"')
// 				i++;
// 			if (line[i] == '\"')
// 				i++;
// 		}
// 		else if (line[i] == '\'')
// 		{
// 			tmp = ms_parsequotes(&line[++i]);
// 			commands = ft_strjoin(commands, tmp);
// 			while (line[i] && line[i] != '\'')
// 				i++;
// 			if (line[i] == '\'')
// 				i++;
// 		}
// 		else
// 			ms_charjoin(commands, line[i++]);
// 	}
// 	return (commands);
// }
