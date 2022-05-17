/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 16:35:22 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_main	*g_main;

int	ms_init(char **envp)
{
	char	buff[501];
	char	*tmp;

	g_main->exit = 0;
	g_main->cmds = 0;
	g_main->running = 0;
	g_main->last_exit_code = 0;
	g_main->envp = ms_array_cpy(envp);
	g_main->envplist = ms_envptolist(envp);
	g_main->fds[0] = 0;
	g_main->fds[1] = 1;
	getcwd(buff, 500);
	tmp = ms_getfromenvp("USER");
	g_main->prompt_msg = ft_strexpend(ft_strexpend(ft_strexpend(ft_strjoin("╭───\
────(\033[34m", tmp), " - ", FALSE), ft_strrchr(buff, '/') + 1, FALSE), \
"\033[0m)\n╰─▻ ", FALSE);
	free(tmp);
	return (0);
}

// void	ms_siginit(t_main *main)
// {
// 	struct sigaction	sa;
// 	sigset_t			sigset;

// 	sigemptyset(&sigset);
// 	ms_signal_handler(-1, 0, main);
// 	sa.sa_flags = SA_SIGINFO;
// 	sa.sa_sigaction = ms_signal_handler;
// 	sigaction(SIGINT, &sa, 0);
// 	sigaction(SIGQUIT, &sa, 0);
// }

void	ms_printtoken(t_list **token)
{
	t_tok	*tok;
	t_list	*lst;

	lst = *token;
	while (lst)
	{	
		tok = (t_tok *)(lst -> content);
		printf("%d %d %s\n", tok -> type, tok -> index, tok -> value);
		lst = lst -> next;
	}
}

void	ms_print_welcome(void)
{
	ft_printf(1, "%s", GREEN);
	ft_printf(1, "Welcome to MiniShell (TM)\n");
	ft_printf(1, "BY:\tRosie & Cristian\n");
	ft_printf(1, "%s", RESETFONT);
}

int	main(int c, char **args, char **envp)
{
	t_list	**tokens;

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
	tokens = ms_tokenize("asdf $abc $? \"x |  $^  as>> $?$PATH'lol' x>> . x$abc\"<'x   $abc   |<>>< x'>>< < << ");
	ms_tokjoining(*tokens);
	ms_spacetokdel(tokens);
	ms_parse_words(tokens);
	ms_printtoken(tokens);
	signal(SIGINT, ms_signal_handler);
	signal(SIGQUIT, ms_signal_handler);
	ms_print_welcome();
	ms_prompt_run();
}
