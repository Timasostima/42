/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 17:36:20 by tkulivar          #+#    #+#             */
/*   Updated: 2025-08-02 17:36:20 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int n)
{
    char *str = ft_itoa(n);
    int len;

    if (!str)
        return 0;
    len = ft_strlen(str);
    ft_putstr_fd(str, FILE_DESC);
    free(str);
    return len;
}

int ft_print_unsigned(unsigned int n)
{
    char *str = ft_utoa(n);
    int len;

    if (!str)
        return 0;
    len = ft_strlen(str);
    ft_putstr_fd(str, FILE_DESC);
    free(str);
    return len;
}
