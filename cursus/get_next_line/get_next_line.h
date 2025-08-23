/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:03:42 by tkulivar          #+#    #+#             */
/*   Updated: 2025/08/19 21:30:40 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		read_file(int fd, char **line);
char	*extract_line(char **line, char *del);
char	*handle_newline_found(char **line, char *buff, char *separator);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int searchedChar);
char	*strjoin_and_update(char **line, char *buffer);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
