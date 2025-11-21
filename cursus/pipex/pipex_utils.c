/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 08:48:27 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-21 08:48:27 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	show_error_and_exit(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execute_command(char *command_string, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(command_string, ' ');
	if (!args || !args[0])
	{
		if (args)
			free_split_array(args);
		show_error_and_exit();
	}
	path = get_command_path(args[0], envp);
	if (!path)
	{
		free_split_array(args);
		show_error_and_exit();
	}
	if (execve(path, args, envp) == -1)
	{
		free(path);
		free_split_array(args);
		show_error_and_exit();
	}
}
