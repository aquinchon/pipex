/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:01:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/24 13:01:41 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_path(char **paths, int i)
{
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	*ft_check_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;	

	i = 0;
	while (paths[i] && paths[i][0])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK))
		{
			ft_free_path(paths, i + 1);
			return (path);
		}
		free (path);
		i++;
	}
	free(paths);
	return (cmd);
}

char	*ft_get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp += 1;
	if (!(envp))
		return (cmd);
	paths = ft_split(*envp + 5, ':');
	path = ft_check_path(paths, cmd);
	if (!path)
		ft_errors(cmd, 2);
	return (path);
}

void	ft_exec(char *arg, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	if (!(arg && arg[0]))
		ft_errors("Permission denied: \n", 4);
	cmd = ft_split(arg, ' ');
	cmd_path = ft_get_path(cmd[0], envp);
	if (execve(cmd_path, cmd, envp))
	{
		if (cmd[0] != cmd_path)
			free(cmd_path);
		ft_errors(cmd[0], 3);
		exit (1);
	}
}
