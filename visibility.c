/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:35:37 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:38:32 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h" // Include the header file

int	check_visibility(int *line, int expected_visible) // Function to check visibility in a line
{
	int	i; // Index for iterating through the line
	int	max_height; // Maximum height among visible numbers
	int	visible_count; // Counter for visible numbers

	i = 0; // Initialize the index
	max_height = 0; // Initialize maximum height
	visible_count = 0; // Initialize the visible numbers counter
	while (i < N) // Loop through the elements of the line
	{
		if (line[i] > max_height) // If the current number is greater than the maximum height
		{
			max_height = line[i]; // Update the maximum height
			visible_count++; // Increment the visible numbers counter
		}
		i++; // Move to the next element
	}
	return (visible_count == expected_visible); // Return 1 if the count of visible numbers matches the expected count
}
