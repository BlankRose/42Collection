/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:43 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 20:57:45 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

builtin_ft	*ms_is_builtin(char *line)
{
	if (!ft_strncmp(line, "exit", 5))
		return (ms_builtin_exit);
	if (!ft_strncmp(line, "echo", 5))
		return (ms_builtin_echo);
	if (!ft_strncmp(line, "env", 4))
		return (ms_builtin_env);
	if (!ft_strncmp(line, "pwd", 4))
		return (ms_builtin_pwd);
	if (!ft_strncmp(line, "export", 8))
		return (ms_builtin_export);
	if (!ft_strncmp(line, "unset", 6))
		return (ms_builtin_unset);
	if (!ft_strncmp(line, "cd", 3))
		return (ms_builtin_cd);
	return (0);
}

static t_list	**ms_prompt_tokenize(char *line)
{
	t_list	**tokens;

	tokens = ms_tokenize(line);
	ms_tokjoining(*tokens);
	ms_parse_words(tokens);
	ms_wordquotesjoining(*tokens);
	ms_spacetokdel(tokens);
	if (ms_redircheck(*tokens) || ms_pipecheck(*tokens))
	{
		printf("%sMiniShell: parse error\n%s", RED, RESETFONT);
		ft_lstclear(tokens, free);
		return (0);
	}
	ms_redirset(tokens);
	return (tokens);
}

static int	ms_prompt_execute(char *line)
{
	g_main->tokens = ms_prompt_tokenize(line);
	if (!g_main->tokens)
		return (1);
	g_main->envp = ms_lsttoarr(g_main->envplist);
	g_main->cmds = ms_tokens2args(g_main->tokens);
	pipex(g_main -> pipecount + 1, g_main -> cmds, g_main -> envp);
	ft_lstclear(g_main->tokens, free);
	ft_freemem(g_main->envp);
	return (0);
}

static void	ms_closeallfd(void)
{
	int	i;

	i = 2;
	while (++i <= 256)
		close(i);
}

void	ms_prompt_run(void)
{
	g_main->last_exit_code = 0;
	while (TRUE)
	{
		g_main->line = readline(g_main->prompt_msg);
		if (!g_main->line)
			ms_builtin_exit(1, 0, 0, 1);
		if (!g_main->line[0] || ft_strnchr(g_main->line, ' ') + \
			ft_strnchr(g_main->line, '\t') == ft_strlen(g_main->line))
		{
			free(g_main->line);
			continue ;
		}
		add_history(g_main->line);
		ms_prompt_execute(g_main->line);
		free(g_main->line);
		ms_closeallfd();
		g_main->fds[0] = 0;
		g_main->fds[1] = 1;
		ms_free_cmd(g_main->cmds);
		g_main->cmds = 0;
		write(1, "\n", 1);
	}
}
