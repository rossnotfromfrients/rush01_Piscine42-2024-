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

#include "include.h" // Include the header file with necessary function and structure declarations

int	validate_side(int grid[N][N], t_clues clues, int row) // Function to validate the left and right visibility for a specific row
{
	int	reversed[N]; // Array to hold the reversed view of the row
	int	i; // Index for iterating through the row

	if (!check_visibility(grid[row], clues.left[row])) // Check if the current row's left visibility matches the clue
		return (0); // Return 0 if it doesn't match
	i = 0; // Initialize the index
	while (i < N) // Loop to reverse the row for right visibility check
	{
		reversed[i] = grid[row][N - 1 - i]; // Fill the reversed array with elements from the end of the row
		i++; // Move to the next element
	}
	if (!check_visibility(reversed, clues.right[row])) // Check if the reversed row's right visibility matches the clue
		return (0); // Return 0 if it doesn't match
	return (1); // Return 1 if both checks are valid
}

int	validate_column(int grid[N][N], t_clues clues, int col) // Function to validate the top and bottom visibility for a specific column
{
	int	column[N]; // Array to hold the current column's values
	int	reversed[N]; // Array to hold the reversed view of the column
	int	i; // Index for iterating through the column

	i = 0; // Initialize the index
	while (i < N) // Loop to fill the column array
	{
		column[i] = grid[i][col]; // Fill the column array with values from the grid
		i++; // Move to the next element
	}
	if (!check_visibility(column, clues.top[col])) // Check if the column's top visibility matches the clue
		return (0); // Return 0 if it doesn't match
	i = 0; // Reset index for reversing the column
	while (i < N) // Loop to reverse the column for bottom visibility check
	{
		reversed[i] = grid[N - 1 - i][col]; // Fill the reversed array with elements from the end of the column
		i++; // Move to the next element
	}
	if (!check_visibility(reversed, clues.bottom[col])) // Check if the reversed column's bottom visibility matches the clue
		return (0); // Return 0 if it doesn't match
	return (1); // Return 1 if both checks are valid
}

int	is_valid(int grid[N][N], t_clues clues) // Function to validate the entire grid against the clues
{
	int	i; // Index for iterating through the rows and columns

	i = 0; // Initialize the index for row validation
	while (i < N) // Loop through each row to validate
	{
		if (!validate_side(grid, clues, i)) // Validate the sides for the current row
			return (0); // Return 0 if any validation fails
		i++; // Move to the next row
	}
	i = 0; // Reset index for column validation
	while (i < N) // Loop through each column to validate
	{
		if (!validate_column(grid, clues, i)) // Validate the columns for the current column
			return (0); // Return 0 if any validation fails
		i++; // Move to the next column
	}
	return (1); // Return 1 if all validations pass
}

