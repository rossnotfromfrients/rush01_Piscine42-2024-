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

#include "include.h"

int	check_visibility(int *line, int expected_visible)
{
	int	i;
	int	max_height;
	int	visible_count;

	i = 0;
	max_height = 0;
	visible_count = 0;
	while (i < N)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count == expected_visible);
}
