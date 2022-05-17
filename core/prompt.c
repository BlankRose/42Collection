/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:43 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 17:36:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

// static builtin_ft	*ms_is_builtin(char *line)
// {
// 	if (!ft_strncmp(line, "exit", 5))
// 		return (ms_builtin_exit);
// 	if (!ft_strncmp(line, "echo", 5))
// 		return (ms_builtin_echo);
// 	if (!ft_strncmp(line, "env", 4))
// 		return (ms_builtin_env);
// 	if (!ft_strncmp(line, "pwd", 4))
// 		return (ms_builtin_pwd);
// 	return (0);
// }

// static char	*ms_pre_emptive2(char *new, char **line)
// {
// 	if (*line && !ft_strncmp(*line, "$?", 2))
// 	{
// 		new = ft_strexpend(new, ft_itoa(g_main->last_exit_code), TRUE);
// 		*line += 2;
// 	}
// 	if (*line && **line == '$')
// 	{
// 		new = ft_strexpend(new, ms_getfromenvp(*line + 1), TRUE);
// 		*line += ft_strlen(*line) - ft_strlen(ft_strchrset(*line + 1, " \"\'$"));
// 	}
// 	if (*line && **line == '\'')
// 	{
// 		new = ft_strexpend(new, ft_substr(*line, 0, ft_strlen(*line) -
// 			ft_strlen(ft_strchr(*(line + 1), '\'')) + 2), TRUE);
// 		*line += ft_strlen(*line) - ft_strlen(ft_strchr(*line + 1, '\''));
// 		if (**line == '\'')
// 			(*line)++;
// 	}
// 	return (new);
// }

// static char	*ms_pre_emptive(char *line)
// {
// 	char	*new;

// 	new = 0;
// 	while (line && *line)
// 	{
// 		new = ms_pre_emptive2(new, &line);
// 		if (line && *line && !ft_isset(*line, "$\'"))
// 		{
// 			new = ft_strexpend(new, ft_substr(line, 0,
// 				ft_strlenlimitset(line, "$\'")), TRUE);
// 			line = line + ft_strlenlimitset(line, "$\'");
// 		}
// 	}
// 	return (new);
// }

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

// static void	ms_prompt_execute(char *line, t_list **tokens)
// {
// 	builtin_ft	*ft;
// 	char		*target;

// 	if (!line)
// 		return ;
// 	ft = ms_is_builtin(g_main->cmds[0][0]);
// 	if (ft)
// 		ft(ms_arraylen(g_main->cmds[0]), g_main->cmds[0], g_main->envp);
// 	else
// 	{
// 		target = ft_getbin(g_main->cmds[0][0], g_main->envp);
// 		if (!target)
// 			printf("%sMiniShell: command not found: %s\n%s", \
// 			RED, g_main->cmds[0][0], RESETFONT);
// 		else
// 			execve(target, g_main->cmds[0], g_main->envp);
// 	}
// 	free(line);
// }

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
			printf("%s\n", token->value);
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
	char	***args;

	if (ms_redircheck(*tokens) == -1)
		return (printf("Redirect tokens non valides\n"));
	args = ms_tokens2args(tokens);
	ms_print_cmd(args);
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
