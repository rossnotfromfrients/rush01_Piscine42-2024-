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

#include "include.h" // Include the header file

int	is_safe(int grid[N][N], int row, int col, int num) // Function to check if it's safe to insert a number
{
	int	x; // Index for iterating through the row and column

	x = 0; // Initialize the index
	while (x < N) // Loop through the elements of the row
	{
		if (grid[row][x] == num || grid[x][col] == num) // Check if the number already exists in the row or column
			return (0); // Return 0 if the number is present
		x++; // Move to the next element
	}
	return (1); // Return 1 if the insertion is safe
}
