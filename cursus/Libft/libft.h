/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 21:22:02 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-10 21:22:02 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *str);

void	*ft_memset(void *s, int c, long unsigned int n);
void	ft_bzero(void *s, long unsigned int n);
void	*ft_memcpy(void *dest, const void *src, long unsigned int n);
void	*ft_memmove(void *dest, const void *src, long unsigned int n);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, long unsigned int n);
void	*ft_memchr(const void *s, int c, long unsigned int);
int		ft_memcmp(const void *s1, const void *s2, long unsigned int n);
char	*ft_strnstr(const char *big, const char *little, long unsigned int len);
int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
