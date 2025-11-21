/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 09:31:54 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-21 09:31:54 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_absolute_path(char *command)
{
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) == 0)
			return (ft_strdup(command));
	}
	return (NULL);
}

static char	*search_in_path_directories(char *command, char **directories)
{
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (directories[i])
	{
		temp = ft_strjoin(directories[i], "/");
		full_path = ft_strjoin(temp, command);
		free(temp);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_command_path(char *command, char **envp)
{
	char	**directories;
	char	*path;
	int		i;

	path = check_absolute_path(command);
	if (path)
		return (path);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	directories = ft_split(envp[i] + 5, ':');
	path = search_in_path_directories(command, directories);
	free_split_array(directories);
	return (path);
}
