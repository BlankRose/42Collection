/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:48:29 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 14:38:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/core.h"

static char	*ms_getnextcmd(char *line)
{
	int		hasquote;

	hasquote = 0;
	if (!line)
		return (0);
	else if (*line && !ms_isoperator(*line))
	{
		while (*line && (!ms_isoperator(*line) || ft_isspace(*line) \
			|| hasquote))
		{
			hasquote = ms_checkquote(*line, hasquote);
			line++;
		}
		return (line);
	}
	else
	{
		while (*line && (ms_isoperator(*line) || ft_isspace(*line)))
			line++;
		return (line);
	}
}

static size_t	ms_count_cmd(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		line = ms_getnextcmd(line);
		if (line)
			i++;
	}
	return (i);
}

char	***ms_split_cmd(char *line)
{
	char		***res;
	char		*tmp;
	t_vector3	v;

	if (!line)
		return (0);
	v = ft_vector3_new(ms_count_cmd(line), 0, 0);
	res = (char ***) ft_calloc(v.x + 1, sizeof(char **));
	if (!res)
		return (0);
	while (v.y < v.x)
	{
		tmp = 0;
		tmp = ms_getnextcmd(line);
		tmp = ft_substr(line, 0, ft_strlen(line) - ft_strlen(tmp));
		res[v.y] = ms_splitadv(tmp, ' ');
		line = ms_getnextcmd(line);
		free (tmp);
		v.y++;
	}
	res[v.x] = 0;
	return (res);
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
			printf("%d\t%s\n", v.y, cmd[v.x][v.y]);
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
