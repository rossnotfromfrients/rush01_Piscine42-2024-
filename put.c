/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:55:57 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 22:02:10 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h" // Include the header file

int	*ft_extrval(char *str) // Function to extract values from a string
{
	int	i; // Index for iterating through the string
	int	j; // Index for writing to the array
	int	*strex; // Array for storing extracted values

	i = 0; // Initialize the string index
	j = 0; // Initialize the array index
	strex = (int *)malloc(N * N * sizeof(int)); // Allocate memory for the array
	if (!strex) // Check if memory allocation was successful
	{
		write (1, "Memory allocation error.\n", 25); // Error message
		return (NULL); // Return NULL in case of error
	}
	while (str[i]) // Loop through the characters of the string
	{
		if (str[i] >= '1' && str[i] <= '4') // Check if the character is a valid value
			strex[j++] = str[i] - '0'; // Convert character to integer and store it in the array
		i++; // Move to the next character
	}
	if (j != 16) // Check if exactly 16 values were extracted
	{
		free(strex); // Free the allocated memory
		write (1, "Input incorrect.\n", 17); // Error message
		return (NULL); // Return NULL in case of error
	}
	return (strex); // Return the array with extracted values
}

int	put_val(char *str, t_clues *clues) // Function to fill the t_clues structure
{
	int	*n; // Pointer for the array of extracted values
	int	i; // Index for iterating through the values

	n = ft_extrval(str); // Extract values from the string
	if (n == NULL) // Check for errors
		return (1); // Return 1 in case of error
	i = 0; // Initialize the index
	while (i < N) // Fill the t_clues structure
	{
		clues->top[i] = n[i]; // Fill the top array
		clues->bottom[i] = n[i + N]; // Fill the bottom array
		clues->left[i] = n[i + 2 * N]; // Fill the left array
		clues->right[i] = n[i + 3 * N]; // Fill the right array
		i++; // Move to the next value
	}
	free(n); // Free the allocated memory for the extracted values array
	return (0); // Return 0 in case of successful execution
}
