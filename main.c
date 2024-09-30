/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:37 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:26:40 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv)
{
	t_clues	clues;

	if (argc == 2)
	{
		if (put_val(argv[1], &clues) == 1)
			return (1);
		initialize_grid_and_solve(clues);
	}
	return (0);
}
