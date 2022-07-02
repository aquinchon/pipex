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
		unlink("/tmp/heredoc_tmp");
	close(fdout);
	return (0);
}
