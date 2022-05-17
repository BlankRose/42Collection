/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:43 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 18:45:51 by flcollar         ###   ########.fr       */
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

static t_list	**ms_prompt_tokenize(char *line)
{
	t_list	**tokens;

	tokens = ms_tokenize(line);
	ms_tokjoining(*tokens);
	ms_parse_words(tokens);
	ms_wordquotesjoining(*tokens);
	ms_spacetokdel(tokens);
	return (tokens);
}

static size_t	ms_count_entries(t_list **tokens)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = *tokens;
	while (current)
	{
		if (((t_tok *) current->content)->type == PIPE)
			i++;
		current = current->next;
	}
	return (i);
}

static size_t	ms_count_subentries(t_list **tokens)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = *tokens;
	while (current)
	{
		if (((t_tok *) current->content)->type != PIPE)
			i++;
		current = current->next;
	}
	return (i);
}

static char	***ms_tokens2args(t_list **tokens)
{
	t_list		*current;
	t_tok		*token;
	char		***args;
	t_vector3	v;

	v = ft_vector3_new(0, 0, 0);
	current = *tokens;
	args = (char ***) malloc(sizeof(char **) * ms_count_entries(tokens) + 2);
	while (current)
	{
		v.y = 0;
		token = (t_tok *) current->content;
		args[v.x] = (char **) malloc(sizeof(char *) * \
			ms_count_subentries(&current) + 1);
		while (current && token && token->type != PIPE)
		{
			args[v.x][v.y++] = token->value;
			current = current->next;
			if (current)
				token = (t_tok *) current->content;
			else
				token = 0;
		}
		if (token && token->type == PIPE)
			current = current->next;
		args[v.x][v.y] = 0;
		v.x++;
	}
	args[v.x] = 0;
	return (args);
}

static int	ms_prompt_execute(t_list **tokens)
{
	builtin_ft	*ft;
	char		*target;

	if (ms_redircheck(*tokens) || ms_pipecheck(*tokens))
		return (printf("%sMiniShell: parse error\n%s", RED, RESETFONT));
	g_main->cmds = ms_tokens2args(tokens);
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
	ms_free_cmd(g_main->cmds);
	return (0);
}

void	ms_prompt_run(void)
{
	char		*line;

	while (TRUE)
	{
		line = readline(g_main->prompt_msg);
		if (!line)
			ms_builtin_exit(1, 0, 0);
		if (!line[0])
			continue ;
		add_history(line);
		ms_prompt_execute(ms_prompt_tokenize(line));
		free(line);
	}
}
