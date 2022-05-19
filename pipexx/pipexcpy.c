/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:35:42 by cciobanu          #+#    #+#             */
/*   Updated: 2022/05/17 18:56:54 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_process(char **command, char **envp)
{
	char	*path;
	// int i = -1;

	// while (command[++i])
	// 	printf("%s ",command[i]);
	// printf("\n");
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


static	void	ft_processfirst(char **command, char **envp, int inputfd, int outputfd)
{
	pid_t	father;
	int		fd[2];
	int		status;

	pipe(fd);
	father = fork();
	if (father == -1)
		exit(2);
	if (father)
	{
		close(fd[1]);
		dup2(fd[0], inputfd);	
		waitpid(father, &status, 0);
	}
	else
	{
		close(fd[0]);
		
		dup2(inputfd, STDIN_FILENO);
		
		if (outputfd == -1)
			dup2(fd[1], STDOUT_FILENO);
		
		else 
			dup2(outputfd, STDOUT_FILENO);
		
		
		if (inputfd < 0)
		{
			exit(0);
		}
		else
			ft_process(command, envp);
	}
}



static	void	ft_processlast(char **command, char **envp, int count , int in, int out, int flag)
{
	pid_t	father;
	int		status;

	father = fork();

	if (father == -1)
		exit(2);
	if (father)
	{
		waitpid(father, &status, 0);
	}
	else
	{
			if (!flag)
				dup2(in, STDIN_FILENO);
			dup2(out, STDOUT_FILENO);

			if (count > 1)
				count++;
			ft_process(command, envp);
	}
}


int	pipex(int *fds, int argc, char ***argv, char **envp)
{
	int	input_file;
	int	output_file;
	int	count;

	//int fd;

	count = 1;
	//fd = open("test1.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (argc == 1)
	{
		input_file = fds[0];
		output_file = fds[1];

		ft_processlast(argv[0], envp, argc, input_file, output_file, 0);
		printf("FDS : %d %d \n", input_file, output_file);

		return (0);
	}
	else if (argc >= 2)
	{
		input_file = fds[0];
		output_file = fds[1];

		int tmpfd = dup(STDIN_FILENO);

		ft_processfirst(argv[0], envp, tmpfd, -1);
		
		while (count < argc - 1)
			ft_processfirst(argv[count++], envp, tmpfd, -1);
		
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
