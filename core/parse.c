/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:43:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 19:47:59 by flcollar         ###   ########.fr       */
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
	tmp = "";
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
	tmp = "";
	i = 0;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$')
		{
			//TO-DO  Get the value from ENVP
			env = ms_getfromenvp(&str[++i]);

			if (env && env[0])
			{
				tmp = ft_strjoin(tmp, env);
				i += ft_strlen(env);
			}
			while (str[i] && str[i] != '\"' && str[i] != '$'
				&& !ft_isspace(str[i]))
				i++;
		}
		else
			tmp = ms_charjoin(tmp, str[i++]);
	}
	if (!str[i])
	{
		perror("Errors in opening double quotes");
		exit(1);
	}
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
