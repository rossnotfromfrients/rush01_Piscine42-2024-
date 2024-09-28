#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// 1. Input Parsing Function
int	parse_input(char *input, int views[SIZE * 4])
{
	int i = 0;
	int j = 0;

	while (input[i] && j < SIZE * 4)
	{
		// Check if the current character is a digit between '1' and '4'
		if (input[i] >= '1' && input[i] <= '4')
		{
			views[j] = input[i] - '0';  // Convert character to integer
			j++;
		}
		// Between numbers there should be a space
		else if (input[i] != ' ')
			return (0);  // Return error if it's not a valid input
		i++;
	}

	// If the number of parsed digits is not exactly 16, return error
	if (j != SIZE * 4)
		return (0);
	return (1);
}
