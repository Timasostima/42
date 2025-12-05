/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_conversion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-05 21:28:17 by tkulivar          #+#    #+#             */
/*   Updated: 2025-12-05 21:28:17 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERSION_H
# define LIBFT_CONVERSION_H

# include "../libft.h"

/* ************************************************************************** */
/*                          TYPE CONVERSION                                   */
/* ************************************************************************** */
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
double	ft_atof(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

#endif
