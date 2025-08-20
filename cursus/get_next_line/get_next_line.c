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

char	*ft_strjoin_end(char const *s1, char const *s2, int index)
{
	int		size_s1;
	int		size_s2;
	char	*res;

	if (!s1 && !s2)
		return (ft_strdup_end("", 0));
	if (!s1)
		return (ft_strdup_end(s2, index));
	if (!s2)
		return (ft_strdup_end(s1, 0));
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = ft_calloc(size_s1 + size_s2 + 1 - (size_s2 - index), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, size_s1 + 1);
	ft_strlcpy(&res[size_s1], s2, size_s2 + 1 - (size_s2 - index));
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	sub_len;
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup_end("", 0));
	sub_len = str_len - start;
	if (sub_len > len)
		sub_len = len;
	substr = malloc(sub_len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*read_file(int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0){
		free (cup_buffer);
		return (NULL);
	}
	return (cup_buffer);
}

char	*check_endline(char **line, char **buff)
{
	char	*result_line;
	char	*del;

	del = ft_strchr(*buff, '\n');
	if (del != NULL)
	{
		result_line = ft_strjoin_end(*line, *buff, (int)(del - *buff) + 1);
		if (*line)
			free(*line);
		*line = ft_substr(*buff, (int)(del - *buff) + 1, ft_strlen(*buff));
		free(*buff);
		return (result_line);
	}
	else
	{
		result_line = ft_strjoin_end(*line, *buff, (int)ft_strlen(*buff));
		if (*line)
			free(*line);
		*line = result_line;
		free(*buff);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result_line;
	char		*buff;

	while (1)
	{
		buff = read_file(fd);
		if (!buff)
		{
			if (line)
			{
				result_line = line;
				line = NULL;
				return (result_line);
			}
			return (NULL);
		}
		result_line = check_endline(&line, &buff);
		if (result_line)
			return (result_line);
	}
}

int main(int argc, char *argv[])
{
	char 	*res;
	(void)	argc;
	int		fd;

	if (!argv[1])
		fd = open("kikotee", O_RDONLY);
	else if (strcmp(argv[1], "stdin") == 0)
		fd = 1;
	else
		fd = open(argv[1], O_RDONLY);

	while(1){
		res = get_next_line(fd);
		if (!res || (fd == 1 && strcmp(res, "eof\n") == 0))
			break;
		printf("%s", res);
		free(res);
	}
	free(res);
	return (fd);
}