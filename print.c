/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:30:57 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:35:14 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h" // Include the header file

void	print_row(int *row) // Function to print a single row
{
	char	buffer[12]; // Buffer for storing the string representation of the number
	int		j; // Index for iterating through the row elements
	int		k; // Index for writing to the buffer

	j = 0; // Initialize the row index
	while (j < N) // Loop through the elements of the row
	{
		int_to_str(row[j], buffer); // Convert the number to a string
		k = 0; // Initialize the buffer index
		while (buffer[k] != '\0') // Print the string character by character
			write (1, &buffer[k++], 1); // Write each character to standard output
		if (j < N - 1) // If this is not the last element of the row
			write (1, " ", 1); // Print a space
		j++; // Move to the next element
	}
	write (1, "\n", 1); // Print a new line after finishing the row
}

void	print_matrix(int grid[N][N]) // Function to print the entire matrix
{
	int	i; // Index for iterating through the rows

	i = 0; // Initialize the row index
	while (i < N) // Loop through the rows
	{
		print_row(grid[i]); // Print the current row
		i++; // Move to the next row
	}
}
