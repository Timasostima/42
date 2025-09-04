/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:21:30 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/19 21:25:54 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **line, char *del)
{
	char		*result_line;
	int			len;
	char		*new_line;

	result_line = malloc((del - *line + 1) + 1);
	if (!result_line)
		return (NULL);
	ft_strlcpy(result_line, *line, (del - *line + 1) + 1);
	len = ft_strlen(*line) - (del - *line + 1);
	new_line = NULL;
	if (len > 0)
	{
		new_line = malloc(len + 1);
		if (!new_line)
			return (free(result_line), NULL);
		ft_strlcpy(new_line, del + 1, len + 1);
	}
	free(*line);
	*line = new_line;
	return (result_line);
}

int	read_file(int fd, char **line)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!strjoin_and_update(line, buffer))
		{
			free(buffer);
			return (-1);
		}
		free(buffer);
		return (1);
	}
	if (bytes_read == -1 && *line)
	{
		free(*line);
		*line = NULL;
	}
	free(buffer);
	return (0);
}

char	*manage_line(char **line)
{
	char		*del;

	if (*line)
	{
		del = ft_strchr(*line, '\n');
		if (del)
			return (extract_line(line, del));
	}
	return (NULL);
}

char	*free_read(int read_result, char **line, char **result_line)
{
	if (read_result == -1 && *line)
	{
		free(*line);
		*line = NULL;
	}
	if (read_result == 0 && *line && **line)
	{
		*result_line = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (*result_line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result_line;
	int			read_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		result_line = manage_line(&line);
		if (result_line)
			return (result_line);
		read_result = read_file(fd, &line);
		if (read_result < 1)
			return (free_read(read_result, &line, &result_line));
	}
}

// int main(int argc, char *argv[])
// {
// 	char 	*res;
// 	(void)	argc;
// 	int		fd;

// 	if (!argv[1])
// 		fd = open("kikotee", O_RDONLY);
// 	else if (strcmp(argv[1], "stdin") == 0)
// 		fd = 1;
// 	else
// 		fd = open(argv[1], O_RDONLY);

// 	while(1){
// 		res = get_next_line(fd);
// 		if (!res || (fd == 1 && strcmp(res, "eof\n") == 0))
// 			break;
// 		printf("%s", res);
// 		free(res);
// 	}
// 	free(res);
// 	close(fd);
// 	return (fd);
// }
