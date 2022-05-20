/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:35:42 by cciobanu          #+#    #+#             */
/*   Updated: 2022/05/20 15:34:17 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


static void	ft_process(char **command, char **envp, int fdout)
{
	char	*path;
	builtin_ft	*ft;

	ft = ms_is_builtin(command[0]);
	
	if (ft)
		ft(ms_arraylen(command), command, envp, fdout);
	else 
	{
		path = ft_getbin(command[0], envp);
		if (path)
		{
			command[0] = path;
			execve(command[0], command, envp);
		}
		ft_freemem(command);
		free(path);
		perror("Error in command processing ");
		exit(127);
	}
}


static	void	ft_processfirst(char **command, char **envp, int inputfd, int outputfd)
{
	pid_t	father;
	int		fd[2];

	pipe(fd);
	//ft_printf(2, "%d %d %d %d \n", fd[0], fd[1], inputfd, outputfd);

	father = fork();
	if (father == -1)
		exit(2);
	if (father)
	{
		close(fd[1]);
		
		dup2(fd[0], inputfd);	
		
		//printf("INPUT FD et FD[0] %d %d \n", inputfd, fd[0]);
		//ft_printf(2, "%d %d %d %d \n", fd[0], fd[1], inputfd, outputfd);
		waitpid(father, &g_main -> last_exit_code, 0);
	}
	else
	{
		close(fd[0]);
		
		dup2(inputfd, STDIN_FILENO);		
		
		if (outputfd == -1)
			dup2(fd[1], STDOUT_FILENO);		
		
		else 
			dup2(outputfd, STDOUT_FILENO);

		
		ft_process(command, envp, fd[1]);
		exit(0);
	}
}

static	void	ft_processone(char **command, char **envp, int in, int out)
{
	pid_t	father;

	father = fork();
	if (father == -1)
		exit(2);
	if (father)
		waitpid(father, &g_main -> last_exit_code, 0);
	else
	{
			dup2(in, STDIN_FILENO);
			dup2(out, STDOUT_FILENO);
			ft_process(command, envp, STDOUT_FILENO);
			exit (0);
	}
}

int	pipex(int argc, char ***argv, char **envp)
{
	builtin_ft	*ft;
	int			input_file;
	int			output_file;
	int			count;
	int			tmpfd;

	
	input_file = g_main -> fds[0];
	output_file = g_main -> fds[1];

	count = 1;
	if (argc == 1)
	{
		ft = ms_is_builtin(argv[0][0]);
		if (ft)
			ft(ms_arraylen(argv[0]), argv[0], envp, output_file);
		else
			ft_processone(argv[0], envp, input_file, output_file);
		return (0);
	}
	else if (argc >= 2)
	{
		tmpfd = dup(input_file);

		ft_processfirst(argv[0], envp, tmpfd, -1);		
		while (count < argc - 1)
			ft_processfirst(argv[count++], envp, tmpfd, -1);	

		ft = ms_is_builtin(argv[count][0]);
		if (ft)
			ft(ms_arraylen(argv[count]), argv[count], envp, output_file);
		else
			ft_processfirst(argv[count], envp, tmpfd, output_file);
		return (0);
	}
	else
	{
		perror("Error : You should give at least 2 atguments!");
		return (1);
	}
	return (0);
}
