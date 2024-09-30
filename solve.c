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

#include "include.h" // Include the header file

int	solve_recursive(int grid[N][N], t_clues clues, int row, int col) // Recursive function to solve the puzzle
{
	int	num; // Variable for the current number

	if (row == N) // Check if we reached the end of the grid
		return (is_valid(grid, clues)); // If yes, check the validity of the current grid
	if (col == N) // If reached the end of the row
		return (solve_recursive(grid, clues, row + 1, 0)); // Move to the next row
	num = 1; // Start with the number 1
	while (num <= N) // Loop through possible values
	{
		if (is_safe(grid, row, col, num)) // Check if the current number can be inserted
		{
			grid[row][col] = num; // Insert the number into the grid
			if (solve_recursive(grid, clues, row, col + 1)) // Recursive call for the next position
				return (1); // Return 1 if a solution is found
			grid[row][col] = 0; // If no solution was found, reset the value
		}
		num++; // Move to the next number
	}
	return (0); // Return 0 if no solution was found
}

void	initialize_grid_and_solve(t_clues clues) // Function to initialize the grid and start solving
{
	int	grid[N][N]; // Declare the grid
	int	i; // Index for rows
	int	j; // Index for columns

	i = 0; // Initialize the row index
	while (i < N) // Loop through the rows
	{
		j = 0; // Initialize the column index
		while (j < N) // Loop through the columns
		{
			grid[i][j] = 0; // Initialize the value in the grid
			j++; // Move to the next column
		}
		i++; // Move to the next row
	}
	if (solve_recursive(grid, clues, 0, 0)) // Start the recursive solving
		print_matrix(grid); // If a solution is found, print the matrix
	else
		write (1, "No solution found.\n", 20); // If no solution, print a message
}
