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

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;

	if (argc != 5)
		ft_errors("Invalid number of arguments.", 1);
	fdin = ft_open_file(argv[1], 0);
	fdout = ft_open_file(argv[4], 1);
	dup2(fdin, 0);
	dup2(fdout, 1);
	ft_fork(argc, argv, envp, fdout);
	close(fdin);
	close(fdout);
	return (0);
}
