/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:09:32 by aquincho          #+#    #+#             */
/*   Updated: 2022/07/01 09:09:35 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_process_pipe(int fdout, int pipe_fd[2], int pid, int pipe_out)
{
	if (pid)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
	else
	{
		close(pipe_fd[0]);
		if (!pipe_out)
			dup2(fdout, 1);
		else
			dup2(pipe_fd[1], 1);
	}
}

void	ft_fork(int argc, char **argv, char **envp, int fdout)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		i;

	i = 1;
	if (!ft_strncmp(argv[1], "here_doc\0", 9))
		i = 2;
	while (++i < argc - 1)
	{
		if (pipe(pipe_fd) == -1)
			ft_errors("pipe: ", 0);
		pid = fork();
		if (pid < 0)
			ft_errors("fork: ", 0);
		else if (pid == 0)
		{
			ft_process_pipe(fdout, pipe_fd, pid, i < argc - 2);
			ft_exec(argv[i], envp);
		}
		else
			ft_process_pipe(fdout, pipe_fd, pid, 0);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	waitpid(-1, NULL, 0);
}
