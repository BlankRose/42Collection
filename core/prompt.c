/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:43 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 00:10:39 by flcollar         ###   ########.fr       */
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

static char	*ms_pre_emptive2(char *new, char **line)
{
	if (*line && !ft_strncmp(*line, "$?", 2))
	{
		new = ft_strexpend(new, ft_itoa(g_main->last_exit_code), TRUE);
		*line += 2;
	}
	if (*line && **line == '$')
	{
		new = ft_strexpend(new, ms_getfromenvp(*line + 1), TRUE);
		*line += ft_strlen(*line) - ft_strlen(ft_strchrset(*line + 1, " \"\'$"));
	}
	if (*line && **line == '\'')
	{
		new = ft_strexpend(new, ft_substr(*line, 0, ft_strlen(*line) - \
			ft_strlen(ft_strchr(*(line + 1), '\'')) + 2), TRUE);
		*line += ft_strlen(*line) - ft_strlen(ft_strchr(*line + 1, '\''));
		if (**line == '\'')
			(*line)++;
	}
	return (new);
}

static char	*ms_pre_emptive(char *line)
{
	char	*new;

	new = 0;
	while (line && *line)
	{
		if (line && *line)
		{
			new = ft_strexpend(new, ft_substr(line, 0, \
				ft_strlenlimitset(line, "$\'")), TRUE);
			line = line + ft_strlenlimitset(line, "$\'");
		}
		new = ms_pre_emptive2(new, &line);
	}
	return (new);
}

static void	ms_prompt_execute(char *line)
{
	builtin_ft	*ft;
	char		*target;

	if (!line)
		return ;
	ft = ms_is_builtin(g_main->cmds[0][0]);
	if (ft)
		ft(ms_arraylen(g_main->cmds[0]), g_main->cmds[0], g_main->envp);
	else
	{
		target = ft_getbin(g_main->cmds[0][0], g_main->envp);
		if (!target)
			printf("%sMiniShell: command not found: %s\n%s", \
			RED, g_main->cmds[0][0], RESETFONT);
		else
			execve(target, g_main->cmds[0], g_main->envp);
	}
	free(line);
}

void	ms_prompt_run(void)
{
	char		*line;
	char		*after;

	while (TRUE)
	{
		line = readline(g_main->prompt_msg);
		if (!line)
			ms_builtin_exit(1, 0, 0);
		if (!line[0])
			continue ;
		add_history(line);
		after = ms_pre_emptive(line);
		if (!after)
		{
			free(line);
			continue ;
		}
		g_main->cmds = ms_split_cmd(after);
		ms_print_cmd(g_main->cmds);
		ms_prompt_execute(after);
		g_main->cmds = ms_free_cmd(g_main->cmds);
		free(line);
	}
}
