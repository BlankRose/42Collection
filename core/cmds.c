/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 17:50:46 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ms_prompt_new(t_main *main)
{
	char	*line;
	char	**commands;
	char	*target;
	int		len;
	char	buf[100];

	line = readline(main->prompt_msg);
	add_history(line);
	if (!ft_strncmp(line, "exit", 4))
		exit(0);
	commands = ft_split(line, ' ');
	len = ms_arraylen(commands);
	chdir("..");
	chdir("minishell");
	getcwd(buf, 50);
	//printf("%s \n", envp[0]);
	//ft_printf(1, "LEN = %d\n", len);
	//pipex(main -> fds, len, commands, main -> envp);
	target = ft_getbin(line, main->envp);
	if (!target)
		printf("%sMiniShell: command not found: %s\n%s", RED, line, RESETFONT);
}
