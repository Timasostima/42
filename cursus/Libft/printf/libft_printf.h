/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 21:28:47 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 21:28:47 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include "../libft.h"

/* ************************************************************************** */
/*                                Prinf                                       */
/* ************************************************************************** */
int		ft_printf(const char *format, ...);
int		ft_handle_format(char c, va_list args);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_percent(void);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned long long n, int uppercase);
int		ft_print_ptr(void *ptr);

#endif
