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

#include "include.h"

void	print_row(int *row)
{
	char	buffer[12];
	int		j;
	int		k;

	j = 0;
	while (j < N)
	{
		int_to_str(row[j], buffer);
		k = 0;
		while (buffer[k] != '\0')
			write (1, &buffer[k++], 1);
		if (j < N - 1)
			write (1, " ", 1);
		j++;
	}
	write (1, "\n", 1);
}

void	print_matrix(int grid[N][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		print_row(grid[i]);
		i++;
	}
}
