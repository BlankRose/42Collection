/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 19:18:06 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
typedef int (builtin_ft)(int, char **, char **);

static builtin_ft	*ms_is_builtin(char *line)
{
	if (!ft_strncmp(line, "exit", 5))
		return (ms_builtin_exit);
	if (!ft_strncmp(line, "echo", 5))
		return (ms_builtin_echo);
	if (!ft_strncmp(line, "env", 4))
		return (ms_builtin_env);
	if (!ft_strncmp(line, "pwd", 4))
		return (ms_builtin_pwd);
	return (0);
}

void	ms_prompt_new(void)
{
	builtin_ft	*ft;
	char		*line;
	char		***commands;
	char		*target;
	//int			len;

	line = readline(g_main->prompt_msg);
	if (line)
		add_history(line);
	ft = ms_is_builtin(line);
	//len = ms_arraylen(commands);
	commands = ms_split_cmd(line);
	ms_print_cmd(commands);
	//printf("%s \n", envp[0]);
	//ft_printf(1, "LEN = %d\n", len);
	//pipex(main -> fds, len, commands, main -> envp);
	if (ft)
		ft(1, 0, g_main->envp);
	else
	{
		target = ft_getbin(line, g_main->envp);
		if (!target)
			printf("%sMiniShell: command not found: %s\n%s", \
			RED, line, RESETFONT);
	}
	commands = ms_free_cmd(commands);
}

char	*ms_charjoin(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(*res) * ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = c;
	res[++i] = '\0';
	//free(str);
	return (res);
}

char	**ms_appendtoarr(char **arr, char *str)
{
	char	**tmp;
	int		i;
	int		len;

	len = ms_arraylen(arr);
	tmp = malloc(sizeof(*tmp) * len + 2);
	i = -1;
	while (arr[++i])
		tmp[i] =arr[i];
	tmp[i++] = str;
	tmp[i] = NULL;
	free(arr);
	return (tmp);
}

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

char	*ms_getfromenvp(char *str)
{
	t_plist	*lst;
	char	*tmp;
	char	*res;
	int		i;

	tmp = malloc(sizeof(*tmp));
	res = malloc(sizeof(*tmp));
	if (!tmp || !res)
		return (NULL);
	tmp[0] = '\0';
	res[0] = '\0';
	lst = g_main -> envplist;
	i = -1;
	while (str[++i] && str[i] != '\"' && str[i] != '$' && !ft_isspace(str[i]))
		tmp = ms_charjoin(tmp, str[i]);
	while (lst)
	{
		if (ft_strlen(tmp) == ft_strlen(lst -> key)
			&& !ft_strncmp(tmp, lst -> key, ft_strlen(tmp)))
		{
			res = ft_strjoin(res, lst -> value);
			break ;
		}
		lst = lst -> next;
	}
	return (res);
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
				tmp = ft_strjoin(tmp , env);
				i += ft_strlen(env);
			}
			while (str[i] && str[i] != '\"' && str[i] != '$'
				&& !ft_isspace(str[i]))
				i++;
		}
		else
			tmp = ms_charjoin(tmp, str[i++]);
	}
	return (tmp);
}

char *ms_parseline(char *line)
{
	char	*commands;
	char	*tmp;
	int		i;

	commands = malloc(sizeof(*commands));
	if (!commands)
		return (NULL);
	commands[0] = '\0';
	i = 0;
	while (line[i] && ms_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			tmp = ms_parsedbquotes(&line[++i]);
			commands = ft_strjoin(commands, tmp);
			while (line[i] && line[i] != '\"')
				i++;
			if (line[i] == '\"')
				i++;
		}
		else if (line[i] == '\'')
		{
			tmp = ms_parsequotes(&line[++i]);
			commands = ft_strjoin(commands, tmp);
			while (line[i] && line[i] != '\'')
				i++;
			if (line[i] == '\'')
				i++;
		}
		else
			ms_charjoin(commands, line[i++]);
	}
	return (commands);
}
