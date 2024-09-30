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

#include "include.h"

int	*ft_extrval(char *str)
{
	int	i;
	int	j;
	int	*strex;

	i = 0;
	j = 0;
	strex = (int *)malloc(N * N * sizeof(int));
	if (!strex)
	{
		write (1, "Memory allocation error.\n", 25);
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			strex[j++] = str[i] - '0';
		i++;
	}
	if (j != 16)
	{
		free(strex);
		write (1, "Input incorrect.\n", 17);
		return (NULL);
	}
	return (strex);
}

int	put_val(char *str, t_clues *clues)
{
	int	*n;
	int	i;

	n = ft_extrval(str);
	if (n == NULL)
		return (1);
	i = 0;
	while (i < N)
	{
		clues->top[i] = n[i];
		clues->bottom[i] = n[i + N];
		clues->left[i] = n[i + 2 * N];
		clues->right[i] = n[i + 3 * N];
		i++;
	}
	free(n);
	return (0);
}
