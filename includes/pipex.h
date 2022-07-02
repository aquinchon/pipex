/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:05:16 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/21 09:05:20 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

/* Gestions des msgs d'erreur ft_errors.c */
int		ft_errors(char *msg, int n_error);
/* Utilitaires pour les cmd ft_cmd_utils */
char	*ft_get_path(char *cmd, char **envp);
void	ft_free_path(char **paths, int i);
int		ft_exec(char *arg, char **envp);
/* ouverture et gesion des fichiers ft_files.c */
int		ft_open_file(char *arg, int mode);
int		ft_heredoc(int argc, char *arg);
int		ft_fork(int argc, char **argv, char **envp, int fdout);

#endif
