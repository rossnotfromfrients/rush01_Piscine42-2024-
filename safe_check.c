/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:47:36 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:49:05 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_safe(int grid[N][N], int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < N)
	{
		if (grid[row][x] == num || grid[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}
