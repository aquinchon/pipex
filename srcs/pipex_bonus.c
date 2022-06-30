/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:18:31 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/24 14:18:35 by aquincho         ###   ########.fr       */
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

static void	ft_fork(int argc, char **argv, char **envp, int fdout)
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
		{
			ft_process_pipe(fdout, pipe_fd, pid, 0);
			waitpid(pid, NULL, 0);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;

	if (argc < 5)
		ft_errors("Invalid number of argumets.", 1);
	if (!ft_strncmp(argv[1], "here_doc\0", 9))
	{
		fdin = ft_heredoc(argc, argv[2]);
		fdout = ft_open_file(argv[argc - 1], 2);
	}
	else
	{
		fdin = ft_open_file(argv[1], 0);
		fdout = ft_open_file(argv[argc - 1], 1);
	}
	dup2(fdin, 0);
	dup2(fdout, 1);
	ft_fork(argc, argv, envp, fdout);
	close(fdin);
	if (!access("/tmp/heredoc_tmp", F_OK))
		unlink(".heredoc_tmp");
	close(fdout);
	return (0);
}
