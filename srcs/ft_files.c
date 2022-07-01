/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:16 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/27 14:52:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_file(char *arg, int mode)
{
	int	fd;

	if (mode == 0)
	{
		if (access(arg, F_OK))
		{
			ft_errors(arg, 0);
			fd = 3;
		}
		else
			fd = open(arg, O_RDONLY);
	}
	else if (mode == 1)
		fd = open(arg, O_CREAT | O_TRUNC | O_RDWR, 00644);
	else
		fd = open(arg, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd < 0 && mode >= 1)
		ft_errors(arg, 5);
	else if (fd < 0 && !mode)
	{
		ft_errors(arg, 0);
		fd = 3;
	}
	return (fd);
}

static void	ft_write_heredoc(int argc)
{
	int	i;

	i = 3;
	while (++i < argc - 1)
		write(1, "pipe ", 5);
	write(1, "heredoc> ", 9);
}

int	ft_heredoc(int argc, char *arg)
{
	char	*line;
	char	*lim;
	int		fdin;

	lim = ft_strjoin(arg, "\n");
	fdin = open("/tmp/heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 00644);
	ft_write_heredoc(argc);
	line = get_next_line(0);
	while (!line || (line && ft_strncmp(line, lim, ft_strlen(lim))))
	{
		if (line)
		{
			write(fdin, line, ft_strlen(line));
			if (line[ft_strlen(line) - 1] == '\n')
				ft_write_heredoc(argc);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(lim);
	close(fdin);
	fdin = ft_open_file("/tmp/heredoc_tmp", 0);
	return (fdin);
}
