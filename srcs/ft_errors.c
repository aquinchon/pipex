/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:12:53 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/24 12:13:13 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_errors_2(char *msg, int n_error)
{
	if (n_error == 3)
	{
		write(2, "Pipex: Command not found: ", 26);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
		free(msg);
		exit (1);
	}
	else if (n_error == 4)
	{
		write(2, "pipex: ", 7);
		write(2, msg, ft_strlen(msg));
		exit (1);
	}
	else if (n_error == 5)
	{
		write(2, "pipex: Cannot open file: ", 25);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
		exit (1);
	}
	return (0);
}

int	ft_errors(char *msg, int n_error)
{
	if (!n_error)
	{
		write(2, "pipex: ", 7);
		perror(msg);
		return (errno);
	}
	else if (n_error == 1)
	{
		write(2, "pipex: ", 7);
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
		exit (1);
	}
	else if (n_error == 2)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
		exit (errno);
	}
	else
		return (ft_errors_2(msg, n_error));
}
