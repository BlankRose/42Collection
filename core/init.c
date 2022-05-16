/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 14:48:43 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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

	line = readline(g_main->prompt_msg);
	if (line)
		add_history(line);
	commands = ms_split_cmd(line);
	ft = ms_is_builtin(commands[0][0]);
	//ms_print_cmd(commands);
	//printf("%s \n", envp[0]);
	//ft_printf(1, "LEN = %d\n", len);
	//pipex(main -> fds, len, commands, main -> envp);
	if (ft)
		ft(ms_arraylen(commands[0]), commands[0], g_main->envp);
	else
	{
		target = ft_getbin(line, g_main->envp);
		if (!target)
			printf("%sMiniShell: command not found: %s\n%s", \
			RED, line, RESETFONT);
	}
	commands = ms_free_cmd(commands);
	free(line);
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
		tmp[i] = arr[i];
	tmp[i++] = str;
	tmp[i] = NULL;
	free(arr);
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
