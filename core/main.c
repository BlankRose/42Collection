/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 20:38:41 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_main	*g_main;

int	ms_init(char **envp)
{
	char	buff[501];

	getcwd(buff, 500);
	g_main->prompt_msg = ft_strexpend(ft_strexpend(ft_strexpend(ft_strjoin("╭───\
────(\033[34m", &envp[1][5]), " - ", FALSE), ft_strrchr(buff, '/') + 1, FALSE), \
"\033[0m)\n╰─▻ ", FALSE);
	g_main->fds[0] = 0;
	g_main->fds[1] = 1;
	g_main->exit = 0;
	g_main->cmds = 0;
	g_main->running = 0;
	g_main->last_exit_code = 0;
	g_main->envp = ms_array_cpy(envp);
	g_main->envplist = ms_envptolist(envp);
	return (0);
}

void	ms_printtoken(t_list *lst)
{
	t_tok	*tok;

	while (lst)
	{	
		tok = (t_tok *)(lst -> content);
		printf("%d %d %s\n", tok -> type, tok -> index, tok -> value);
		lst = lst -> next;
	}
}

int	main(int c, char **args, char **envp)
{
	//t_list *tokens;

	c++;
	args = 0;
	g_main = malloc(sizeof(t_main));
	if (!g_main)
		return (1);
	ms_init(envp);
	//char *test[4] = {"/bin/echo", "\"$PATH\"", "test", NULL};
	//main -> envp = ms_appendtoarr(main -> envp , "abc=123");
	// i = -1;
	// while(main->envp[++i])
	// 	printf("%s \n", main->envp[i]);
	//execve("/bin/echo", test, envp);
	// tokens = ms_tokenize("asdf    as>><<");
	// ms_printtoken(tokens);
	//ms_printlist(main -> envplist);
	signal(SIGINT, ms_signal_handler);
	signal(SIGQUIT, ms_signal_handler);
	ms_prompt_run();
}
