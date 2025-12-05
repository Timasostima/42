/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_checks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 21:27:48 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 21:27:48 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECKS_H
# define LIBFT_CHECKS_H

# include "../libft.h"

/* ************************************************************************** */
/*                          CHECK FUNCTIONS                                   */
/* ************************************************************************** */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isint(const char *str);
int		ft_isfloat(const char *str);

#endif
