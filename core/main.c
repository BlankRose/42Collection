/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 19:51:20 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	ms_startshell(t_main *main)
{
	while (!(main -> exit))
		ms_prompt_new(main);
	return (0);
}


int	ms_init(t_main *main, char **envp)
{
	main->prompt_msg = ft_strexpend(ft_strjoin("╭─────────(\033[34m", \
		&envp[1][5]), " - MINISHELL TM\033[0m)\n╰─▻ ", FALSE);
	main->exit = 0;
	main->fds[0] = 0;
	main->fds[1] = 1;
	envp[3] = ft_strjoin("PATH=./builtin:", &envp[3][5]);
	main->envp = ms_array_cpy(envp);
	main->envplist = ms_envptolist(envp);
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

int	main(int c, char **args, char **envp)
{
	t_main	*main;
	int i;

	c++; // a retirer
	args = 0;
	main = malloc(sizeof(*main));
	if (!main)
		return (1);
	ms_init(main, envp);

	char *test[3] = {"/bin/echo", "$PATH", NULL};

	main -> envp = ms_appendtoarr(main -> envp , "abc=123");
	int	i = -1;
	while(main->envp[++i])
		printf("%s \n", main->envp[i]);

	execve("/bin/echo", test, envp);

	// printf("%s \n", ms_parseline("\"sfasdfds$PATHasdfds$LANG\"  \'   yyy   y\' xxx", main));
	// printf("%s \n", ms_parseline("\"$PATHa$asdfds\"  xxx \'z  $LANG    z\'", main));
	// printf("%s \n", ms_parseline("\"asdfds$PAT\"  xxxx \'     \' ", main));

	//ms_printlist(main -> envplist);

	// ms_siginit(main);

	//ms_startshell(main);
}
