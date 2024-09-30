/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:38:55 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:46:26 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	validate_side(int grid[N][N], t_clues clues, int row)
{
	int	reversed[N];
	int	i;

	if (!check_visibility(grid[row], clues.left[row]))
		return (0);
	i = 0;
	while (i < N)
	{
		reversed[i] = grid[row][N - 1 - i];
		i++;
	}
	if (!check_visibility(reversed, clues.right[row]))
		return (0);
	return (1);
}

int	validate_column(int grid[N][N], t_clues clues, int col)
{
	int	column[N];
	int	reversed[N];
	int	i;

	i = 0;
	while (i < N)
	{
		column[i] = grid[i][col];
		i++;
	}
	if (!check_visibility(column, clues.top[col]))
		return (0);
	i = 0;
	while (i < N)
	{
		reversed[i] = grid[N - 1 - i][col];
		i++;
	}
	if (!check_visibility(reversed, clues.bottom[col]))
		return (0);
	return (1);
}

int	is_valid(int grid[N][N], t_clues clues)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (!validate_side(grid, clues, i))
			return (0);
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (!validate_column(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}
