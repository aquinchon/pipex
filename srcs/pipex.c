/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:00:52 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/21 09:01:37 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_wait(int pid, int pipe_fd[2])
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	waitpid(pid, NULL, 0);
}

static void	ft_fork(int argc, char **argv, char **envp, int fdout)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		if (pipe(pipe_fd) == -1)
			ft_errors("pipe: ", 0);
		pid = fork();
		if (pid < 0)
			ft_errors("fork: ", 0);
		else if (pid == 0)
		{
			close(pipe_fd[0]);
			if (i < argc - 2)
				dup2(pipe_fd[1], 1);
			else
				dup2(fdout, 1);
			ft_exec(argv[i], envp);
		}
		else
			ft_wait(pid, pipe_fd);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;

	if (argc != 5)
		ft_errors("Invalid number of argumets.", 1);
	fdin = ft_open_file(argv[1], 0);
	fdout = ft_open_file(argv[4], 1);
	dup2(fdin, 0);
	dup2(fdout, 1);
	ft_fork(argc, argv, envp, fdout);
	close(fdin);
	close(fdout);
	return (0);
}
