/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:48:29 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 20:01:20 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/core.h"

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
	g_main -> pipecount = i;
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

char	***ms_tokens2args(t_list **tokens)
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

void	ms_print_cmd(char ***cmd)
{
	t_vector2	v;

	v = ft_vector2_new(0, 0);
	if (!cmd)
		return ;
	while (cmd[v.x])
	{
		v.y = 0;
		printf("[CMD %d]==----\n", v.x);
		while (cmd[v.x][v.y])
		{
			printf("%d\t[%s]\n", v.y, cmd[v.x][v.y]);
			v.y++;
		}
		v.x++;
	}
}

char	***ms_free_cmd(char ***cmd)
{
	t_vector2	v;

	v = ft_vector2_new(0, 0);
	if (!cmd)
		return (0);
	while (cmd[v.x])
	{
		v.y = 0;
		while (cmd[v.x][v.y])
		{
			free(cmd[v.x][v.y]);
			v.y++;
		}
		free(cmd[v.x]);
		v.x++;
	}
	free(cmd);
	return (0);
}
