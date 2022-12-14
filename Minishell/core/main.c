/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:12 by flcollar          #+#    #+#             */
/*   Updated: 2022/09/27 20:08:52 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_main	*g_main;

void	ms_set_prompt_msg(void)
{
	char	buff[501];
	char	*tmp;

	getcwd(buff, 500);
	tmp = ms_getfromenvp("USER");
	g_main->prompt_msg = ft_strexpend(ft_strexpend(ft_strexpend(ft_strjoin("╭───\
──────(\033[34m", tmp), " - ", FALSE), ft_strrchr(buff, '/') + 1, FALSE), \
"\033[0m)\n╰─▻ ", FALSE);
	free(tmp);
}

int	ms_init(char **envp)
{
	g_main->envp = 0;
	g_main->cmds = 0;
	g_main->line = 0;
	g_main->tokens = 0;
	g_main->running = 0;
	g_main->pipecount = 0;
	g_main->envplist = ms_envptolist(envp);
	g_main->fds[0] = 0;
	g_main->fds[1] = 1;
	ms_set_prompt_msg();
	return (0);
}

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

static void	ms_print_welcome(void)
{
	ft_printf(1, "\n%s", YELLOW);
	ft_printf(1, " ┌─═══════╤\t    ☲    ☴\n");
	ft_printf(1, " │  ◔ ▿ ◔ │\t $ MiniShell (TM)\n");
	ft_printf(1, " └─┬──╥─╥─┘│\tBY:  Rosie & Cristian\n");
	ft_printf(1, "  ⎧│  ∇ ╟──╯\t      ☵         ☱\n");
	ft_printf(1, "%s", RESETFONT);
}

int	main(int c, char **args, char **envp)
{
	c++;
	args = 0;
	g_main = malloc(sizeof(t_main));
	if (!g_main)
		return (1);
	ms_init(envp);
	signal(SIGINT, ms_signal_handler);
	signal(SIGQUIT, ms_signal_handler);
	ms_print_welcome();
	ms_prompt_run();
}
