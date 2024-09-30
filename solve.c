/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:49:23 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:55:15 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	solve_recursive(int grid[N][N], t_clues clues, int row, int col)
{
	int	num;

	if (row == N)
		return (is_valid(grid, clues));
	if (col == N)
		return (solve_recursive(grid, clues, row + 1, 0));
	num = 1;
	while (num <= N)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_recursive(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	initialize_grid_and_solve(t_clues clues)
{
	int	grid[N][N];
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (solve_recursive(grid, clues, 0, 0))
		print_matrix(grid);
	else
		write (1, "No solution found.\n", 20);
}
