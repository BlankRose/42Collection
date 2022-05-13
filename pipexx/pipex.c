/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:35:42 by cciobanu          #+#    #+#             */
/*   Updated: 2022/05/13 13:08:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(char *command, char **envp)
{
	char	*path;
	char	**arr;

	arr = ft_split(command, ' ');
	path = ft_getbin(arr[0], envp);
	if (path)
	{
		arr[0] = path;
		execve(arr[0], arr, envp);
	}
	ft_freemem(arr);
	free(path);
	perror("Error in command processing ");
	exit(127);
}

void	ft_processfirst(char *command, char **envp, int inputfd)
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
		dup2(fd[0], STDIN_FILENO);
		waitpid(father, &status, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (!inputfd)
			exit(0);
		else
			ft_process(command, envp);
	}
}

int	pipex(int *fds, int argc, char **argv, char **envp)
{
	int	input_file;
	int	output_file;
	int	count;

	count = 0;
	if (argc >= 2)
	{
		input_file = fds[0];
		output_file = fds[1];
		dup2(input_file, STDIN_FILENO);
		dup2(output_file, STDOUT_FILENO);
		ft_processfirst(argv[2], envp, input_file);
		while (count < (argc - 2))
			ft_processfirst(argv[count++], envp, 1);
		ft_process(argv[count], envp);
	}
	else
	{
		perror("Error : You should give at least 4 atguments!");
		exit(1);
	}
	return (0);
}
