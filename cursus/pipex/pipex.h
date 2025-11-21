/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 08:56:33 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-21 08:56:33 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define FILE_DESC 1

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

void	execute_first_command(char **argv, char **envp, int *pipe_fd);
void	execute_second_command(char **argv, char **envp, int *pipe_fd);
char	*get_command_path(char *command, char **envp);
void	show_error_and_exit(void);
void	execute_command(char *command_string, char **envp);
void	free_split_array(char **array);

#endif