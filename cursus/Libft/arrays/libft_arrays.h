/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_arrays.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 21:27:58 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 21:27:58 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAYS_H
# define LIBFT_ARRAYS_H

# include <stddef.h>

/* ************************************************************************** */
/*                          ARRAY FUNCTIONS                                   */
/* ************************************************************************** */
size_t	ft_arsize(void **arr);
void	ft_ariteri(void **arr, void (*f)(void *));
char	*ft_arrmapi(void **arr, void (*f)(void *));

#endif
