/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:47:40 by tkulivar          #+#    #+#             */
/*   Updated: 2024/07/24 20:13:01 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define B_S 10

void	print_sol(int board[B_S])
{
	int		i;
	char	to_print;

	i = 0;
	while (i < B_S)
	{
		to_print = board[i] + '0';
		write(1, &to_print, 1);
		i++;
	}
	write(1, "\n", 1);
}

//only to show the results. Btw,The board is rotated.
/*
void	print_sol2(int board[B_S])
{
    int		i;
    int		j;

    i = 0;
    while (i < B_S)
    {
        j = 0;
        while (j < B_S)
        {
            if (board[i] == j)
                write(1, "Q ", 2);
            else
                write(1, ". ", 2);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    write(1, "\n", 1);
}
*/

int	safe_cell(int board[B_S], int col, int row)
{
	int	board_pos;
	int	j;

	board_pos = col - 1;
	j = 0;
	if (col == 0)
		return (1);
	while (j < B_S)
	{
		if (row == board[j])
			return (0);
		j++;
	}
	j = 1;
	while (board_pos >= 0)
	{
		if (board[board_pos] == row - j
			|| board[board_pos] == row + j)
			return (0);
		board_pos--;
		j++;
	}
	return (1);
}

void	find_solution(int board[B_S], int col, int *sols)
{
	int	row;

	row = 0;
	if (col == B_S)
	{
		*sols = *sols + 1;
		print_sol(board);
		//print_sol2(board);
		return ;
	}
	while (row < B_S)
	{
		if (safe_cell(board, col, row))
		{
			board[col] = row;
			find_solution(board, col + 1, sols);
			board[col] = -1;
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	board[B_S];
	int	sol;
	int	*sols;

	sol = 0;
	sols = &sol;
	i = 0;
	while (i < B_S)
	{
		board[i] = -1;
		i++;
	}
	find_solution(board, 0, sols);
	return (sol);
}

// int	main(void)
// {
// 	int i = ft_ten_queens_puzzle();
// 	if (i == 1)
// 		i = 1;
// 	return (0);
// }
