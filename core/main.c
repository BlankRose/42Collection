/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/12 18:08:03 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int ms_arraylen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}


char **ms_array_cpy(char **arr)
{
	char **res;
	int i;
	int len;

	i = -1;
	len = ms_arraylen(arr);
	res = malloc(sizeof(*res) * len + 1);
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = ft_strdup(arr[i]);
	res[i] = NULL;
	return (res);
}

t_list *ms_arrtolist(char **arr)
{
	retutn (NULL);
}

int ms_startshell(t_main *main)
{
	char *line;
	char **commands;
	int len;
	char buf[100];
	while (!(main -> exit))
	{
		line = readline("%");
		add_history(line);
		if (!ft_strncmp(line , "exit", 4))
			exit(0);
		commands = ft_split(line, ' ');
		len = ms_arraylen(commands);
		chdir("..");
		chdir("minishell");
		getcwd(buf, 50);
		printf("%s \n", buf);

		//printf("%s \n", envp[0]);
		//ft_printf(1, "LEN = %d\n", len);
		//pipex(main -> fds, len, commands, main -> envp);
		printf("%s \n", line);
	}
	return (0);
}

int ms_init(t_main *main, char **envp)
{
	main -> exit = 0;
	main -> fds[0] = 0;
	main -> fds[1] =1;
	main -> envp = ms_array_cpy(envp);

	return (0);
}

int	main(int c, char **args, char **envp)
{
	t_main *main;
	//int i;


	c++; // a retirer
	args = 0;
	main = malloc(sizeof(*main));
	if(!main)
		return (0);
	ms_init(main, envp);

	// i = -1;
	// while(main ->envp[++i])
	// 	printf("%s \n", main -> envp[i]);
	ms_startshell(main);


}
