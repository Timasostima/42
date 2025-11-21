/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 08:46:32 by tkulivar          #+#    #+#             */
/*   Updated: 2025-11-21 08:46:32 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_command(char **argv, char **envp, int *pipe_fd)
{
	int		input_file;

	input_file = open(argv[1], O_RDONLY, 0777);
	if (input_file == -1)
		show_error_and_exit();
	dup2(input_file, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(input_file);
	execute_command(argv[2], envp);
}

void	execute_second_command(char **argv, char **envp, int *pipe_fd)
{
	int		output_file;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file == -1)
		show_error_and_exit();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_file, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(output_file);
	execute_command(argv[3], envp);
}

static int	run_pipeline(char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	first_child_pid;
	pid_t	second_child_pid;
	int		status;

	if (pipe(pipe_fd) == -1)
		show_error_and_exit();
	first_child_pid = fork();
	if (first_child_pid == -1)
		show_error_and_exit();
	if (first_child_pid == 0)
		execute_first_command(argv, envp, pipe_fd);
	second_child_pid = fork();
	if (second_child_pid == -1)
		show_error_and_exit();
	if (second_child_pid == 0)
		execute_second_command(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(first_child_pid, NULL, 0);
	waitpid(second_child_pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	exit_code;

	if (argc == 5)
	{
		exit_code = run_pipeline(argv, envp);
		return (exit_code);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
}
