/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:52 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:29:36 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h" // Include the header file // 

void	int_to_str(int num, char *str) // Function to convert an integer to a string
{
	int	i; // Index for writing to the string
	int	temp_num; // Temporary variable for processing the number

	i = 0; // Initialize index
	if (num == 0) // If the number is zero
	{
		str[i++] = '0'; // Write '0' to the string
		str[i] = '\0'; // Null-terminate the string
		return ; // Exit the function
	}
	temp_num = num; // Save the original number
	while (temp_num > 0) // Determine the length of the number
	{
		temp_num /= 10; // Divide by 10 until it becomes 0
		i++; // Increase the length
	}
	str[i] = '\0'; // Null-terminate the string
	while (num > 0) // Fill the string with digits in reverse order
	{
		str[--i] = (num % 10) + '0'; // Get the last digit and write it to the string
		num /= 10; // Remove the last digit
	}
}

