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

int ms_init(t_main *main)
{
	main -> exit = 0;
	main -> fds[0] = 0;
	main -> fds[1] =1;
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

int ms_startshell(t_main *main)
{
	char *line;
	char **commands;
	int len;
	while (!(main -> exit))
	{
		line = readline("%");
		if (!ft_strncmp(line , "exit", 4))
			exit(0);
		commands = ft_split(line, ' ');
		len = ft_arraylen(commands);
		//printf("%s \n", envp[0]);
		//ft_printf(1, "LEN = %d\n", len);
		pipex(main -> fds, len, commands, main -> envp);
		printf("%s \n", line);
	}
}

int	main(int c, char **args, char **envp)
{
	t_main *main;


	c++; // a retirer
	args = 0;
	main = malloc(sizeof(*main));
	if(!main)
		return (0);
	ft_init(main);
	
	//ft_startshell(main);


}
