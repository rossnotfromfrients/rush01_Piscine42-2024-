#include <stdlib.h>

// Function to calculate the length of a string
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len]) // Iterate through the string until the null byte
		len++;
	return (len); // Return the length of the string
}

// Function to concatenate two strings: append src to dest
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i]) // Find the end of the dest string
		i++;
	j = 0;
	while (src[j]) // Copy characters from src to dest
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0'; // Terminate the string with a null byte
	return (dest); // Return the pointer to dest
}

// Function to calculate the total length of all strings and separators
int	ft_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]); // Add the length of each string
		if (i < size - 1) // If it's not the last string, add the length of the separator
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len); // Return the total length
}

// Main function ft_strjoin
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		i;

	// If size == 0, return an empty string
	if (size == 0)
	{
		result = malloc(1); // Allocate memory for an empty string
		if (result)
			*result = '\0'; // Set the null byte
		return (result);
	}
	total_len = ft_total_length(size, strs, sep); // Calculate total length of the final string
	result = malloc(total_len + 1); // Allocate memory for the final string
	if (!result) // Check if memory allocation was successful
		return (NULL);
	*result = '\0'; // Initialize the final string
	i = 0;
	while (i < size) // Iterate through all strings in strs
	{
		ft_strcat(result, strs[i]); // Append the current string to result
		if (i < size - 1) // If it's not the last string, append the separator
			ft_strcat(result, sep);
		i++;
	}
	return (result); // Return the pointer to the final string
}
